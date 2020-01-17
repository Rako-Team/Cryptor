
void pattern()
{
	int res;
	char *src;
	char *dst;
	int exist;

	PT_ASSING_RANDOM_STR(src, 5, 32);
	PT_ASSING_RANDOM_STR(dst, 5, 32);
	PT_ASSING_RANDOM_NUM(exist, 1, 1);

    res = CopyFile(dst, src, exist);
    if (res)
    {
    	PT_TRASH(res);
    }

    PT_TRASH(res);
}