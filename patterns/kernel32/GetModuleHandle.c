
void pattern()
{
	char *name;
	int module;
	int temp;

	PT_ASSING_RANDOM_NUM(temp, 1, 100);
	PT_ASSING_RANDOM_STR(name, 5, 10);

    module = (int)GetModuleHandleA(name);
    if (module)
    {
    	PT_TRASH(module);
    }

    PT_TRASH(module);
}