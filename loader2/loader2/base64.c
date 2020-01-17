
#include <Windows.h>

#include "main.h"


void base64_decode(
	unsigned char *dst,
	unsigned char *src,
    unsigned int input_length,
    unsigned int output_length,
	void *code_base
	)
{
	unsigned char decoding_table[256];
	unsigned int i, j;
	unsigned int sextet_a, sextet_b, sextet_c, sextet_d;
	unsigned int triple;
	unsigned char *encoding_table;

	encoding_table = (unsigned char*)GET_PTR(encoding_table_func, dc2, code_base);

    for (i = 0; i < 0x40; i++)
        decoding_table[encoding_table[i]] = (unsigned char)i;

    for (i = 0, j = 0; i < input_length;)
	{
        sextet_a = src[i] == '=' ? 0 & i++ : decoding_table[src[i++]];
        sextet_b = src[i] == '=' ? 0 & i++ : decoding_table[src[i++]];
        sextet_c = src[i] == '=' ? 0 & i++ : decoding_table[src[i++]];
        sextet_d = src[i] == '=' ? 0 & i++ : decoding_table[src[i++]];

        triple = (sextet_a << 3 * 6)
                        + (sextet_b << 2 * 6)
                        + (sextet_c << 1 * 6)
                        + (sextet_d << 0 * 6);

        if (j < output_length) dst[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < output_length) dst[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < output_length) dst[j++] = (triple >> 0 * 8) & 0xFF;
    }
}


unsigned int base64_get_decoded_data_length(
	unsigned char *encoded_data,
	unsigned int encoded_data_length
	)
{
	unsigned int decoded_data_length;

	decoded_data_length = encoded_data_length / 4 * 3;
    if (encoded_data[encoded_data_length - 1] == '=') (decoded_data_length)--;
    if (encoded_data[encoded_data_length - 2] == '=') (decoded_data_length)--;

	return decoded_data_length;
}