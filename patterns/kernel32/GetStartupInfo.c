
void pattern()
{
	struct _STARTUPINFOA res;
	long flags;
	int temp;

	PT_ASSING_RANDOM_NUM(temp, 1, 100);

    GetStartupInfo(&res);
    flags = res.dwFlags;

    PT_TRASH(flags);
}