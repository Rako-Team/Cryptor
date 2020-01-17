
void pattern()
{
	int res;
	char *name;
	char buff[32];
	int temp;

	PT_ASSING_RANDOM_NUM(temp, 1, 100);
	PT_ASSING_RANDOM_STR(name, 5, 32);

	res = (int)GetEnvironmentVariable(name, buff, sizeof(buff));
	if (res)
    {
    	PT_TRASH(res);
    }

    PT_TRASH(res);
}