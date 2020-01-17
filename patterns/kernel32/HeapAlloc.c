
void pattern()
{
	void *res;
	void *heap;
	long flag;
	long len;

	heap = GetProcessHeap();

	PT_ASSING_RANDOM_NUM(flag, 0x00000008, 0x00000008);
	PT_ASSING_RANDOM_NUM(len, 1, 50);

    res = HeapAlloc(heap, flag, len);
    if (res)
    {
    	PT_TRASH(len);
    	HeapFree(heap, 0, res);
    }

    PT_TRASH(len);
}