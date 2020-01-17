
void pattern()
{
	char *name;
	int res;
	int temp;

	PT_ASSING_RANDOM_NUM(temp, 1, 100);
	PT_ASSING_RANDOM_STR(name, 5, 32);

    res = DeleteFile(name);
    if (res)
    {
    	PT_TRASH(res);
    }

    PT_TRASH(res);
}