
void pattern()
{
	int res;
	int temp;

	PT_ASSING_RANDOM_NUM(temp, 1, 100);

    res = GetACP();
    if (res)
    {
    	PT_TRASH(res);
    }

    PT_TRASH(res);
}