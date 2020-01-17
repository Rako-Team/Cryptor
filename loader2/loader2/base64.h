#ifndef __BASE64_h__
#define __BASE64_h__

void base64_encode(
	unsigned char *dst,
	unsigned char *src,
    unsigned int input_length
	);

void base64_decode(
	unsigned char *dst,
	unsigned char *src,
    unsigned int input_length,
    unsigned int output_length,
	void *code_base
	);

unsigned int base64_get_encoded_data_length(
	unsigned int input_length
	);

unsigned int base64_get_decoded_data_length(
	unsigned char *encoded_data,
	unsigned int encoded_data_length
	);

#endif /*  __BASE64_h__ */