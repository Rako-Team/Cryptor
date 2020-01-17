
void pattern()
{
	int res;
	int file;
	char *name;
	int mode;

	PT_ASSING_RANDOM_STR(name, 5, 32);
	PT_ASSING_RANDOM_NUM(mode, 0, 5);

    res = AVIFileOpen(&file, name, mode, 0);
    if (res)
    {
    	PT_TRASH(res);
    }

    PT_TRASH(res);
}