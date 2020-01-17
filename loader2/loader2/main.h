
#pragma once


struct params_cb
{
	HINSTANCE	h_instance;
	BOOL		is_resource;
	BOOL		is_base64;
	BOOL		is_packed;
    void		*p_decryption_key;
    int			depacked_data_length;
    void		*p_pe_data_1;
    void		*p_pe_data_2;
    int			pe_data_size_1;
    int			pe_data_size_2;
};


typedef void * (*GETPROCADDRESS) (
	HMODULE hModule,
	LPCSTR lpProcName
	);

typedef void * (*GETMODULEHANDLE) (
	LPCTSTR lpModuleName
	);

typedef void * (*VIRTUALPROTECT) (
	LPVOID lpAddress,
	SIZE_T dwSize,
	DWORD flNewProtect,
	PDWORD lpflOldProtect
	);

typedef void * (*VIRTUALALLOC) (
	LPVOID lpAddress,
	SIZE_T dwSize,
	DWORD flAllocationType,
	DWORD flProtect
	);

typedef void * (*VIRTUALFREE) (
	LPVOID lpAddress,
	SIZE_T dwSize,
	DWORD dwFreeType
	);

typedef void * (*EXITPROCESS) (
	UINT uExitCode
	);

typedef void * (*LOADLIBRARYA) (
	LPCTSTR lpFileName
	);

typedef void * (*GETVERSIONEXA) (
	LPOSVERSIONINFOA lpVersionInfo
	);

typedef wchar_t * (*GETCOMMANDLINEW) (
	void
	);

typedef wchar_t * (*COMMANDLINETOARGVW) (
	LPCWSTR lpCmdLine,
	int *pNumArgs
	);

typedef HRSRC (*FINDRESOURCEA) (
	HMODULE hModule,
	LPCSTR lpName,
	LPCSTR lpType
	);

typedef HGLOBAL (*LOADRESOURCE) (
	HMODULE hModule,
	HRSRC hResInfo
	);

typedef DWORD (*SIZEOFRESOURCE) (
	HMODULE hModule,
	HRSRC hResInfo
	);

typedef void (*OEP) (
	int argc,
	wchar_t *argv
	);

typedef LPVOID (*LOCKRESOURCE) (
	HGLOBAL hResData
	);

struct api_cb
{
	GETMODULEHANDLE			GetModuleHandle;
	GETPROCADDRESS			GetProcAddress;
	VIRTUALPROTECT			VirtualProtect;
	VIRTUALALLOC			VirtualAlloc;
	VIRTUALFREE				VirtualFree;
	EXITPROCESS				ExitProcess;
	LOADLIBRARYA			LoadLibraryA;
	GETVERSIONEXA			GetVersionExA;
	GETCOMMANDLINEW			GetCommandLineW;
	COMMANDLINETOARGVW		CommandLineToArgvW;
	FINDRESOURCEA			FindResourceA;
	LOADRESOURCE			LoadResource;
	SIZEOFRESOURCE			SizeofResource;
	LOCKRESOURCE			LockResource;
};


#define GET_PTR(ptr, start, code_base)			\
		((char *)ptr - (char *)start + (char *)code_base)


extern void *get_code_base();
extern void reset_callbacks();
//extern void crt_memcpy(void *dst, void *src, int mem_size);
//extern void crt_memset(void *pointer, char value, int mem_size);

extern void encoding_table_func();
extern void szGetProcAddress();
extern void szGetModuleHandle();
extern void szKernel32Dll();
extern void szVirtualProtect();
extern void szVirtualAlloc();
extern void szVirtualFree();
extern void szExitProcess();
extern void szLoadLibraryA();
extern void szGetVersionExA();
extern void szShell32Dll();
extern void szGetCommandLineW();
extern void szCommandLineToArgvW();
extern void szFindResourceA();
extern void szLoadResource();
extern void szSizeofResource();
extern void szLockResource();
extern void szComdlg32Dll();

int __stdcall	dc2(struct params_cb *params);
void			*build_image(struct api_cb *p_api, HINSTANCE h_instance, void *pe_data);
void			*load_data_from_resources(struct api_cb *p_api, int *size);
BOOL			api_init(void *code_base, HINSTANCE h_instance, struct api_cb *p_api);
void			*get_proc_address_from_kernel(void *h_instance, char *proc_name);
void			process_import(struct api_cb *p_api, void *pe_mem);