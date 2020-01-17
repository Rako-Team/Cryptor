
#include <Windows.h>


void crt_memcpy(void *dst, void *src, int mem_size)
{
	int i;

	for (i = 0; i < mem_size; i++)
		((char *)dst)[i] = ((char *)src)[i];
}


void crt_memset(void *pointer, char value, int mem_size)
{
	int i;

	for (i = 0; i < mem_size; i++)
		((char *)pointer)[i] = value;
}