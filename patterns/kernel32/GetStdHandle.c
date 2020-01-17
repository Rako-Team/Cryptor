
void pattern()
{
	long std;
	int handle;

	PT_ASSING_RANDOM_NUM(std, 10, 12);

    handle = (int)GetStdHandle(std);
    if (handle)
    {
    	PT_TRASH(handle);
    }

    PT_TRASH(handle);
}