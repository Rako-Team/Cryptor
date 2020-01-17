
void pattern()
{
	long res;
	int temp;

	PT_ASSING_RANDOM_NUM(temp, 1, 100);

    res = GetLastError();
    if (res)
    {
    	PT_TRASH(res);
    }

    PT_TRASH(res);
}