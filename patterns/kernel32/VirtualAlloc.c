
void pattern()
{
	int data;
	int len;
	int type;
	int prot;
	int release;

	PT_ASSING_RANDOM_NUM(len, 1, 4096);
	PT_ASSING_RANDOM_NUM(type, 0x00001000, 0x00001000);
	PT_ASSING_RANDOM_NUM(prot, 0x04, 0x04);

	data = (int)VirtualAlloc(NULL, len, type, prot);
	if (data)
	{
		PT_TRASH(data);
		PT_ASSING_RANDOM_NUM(release, 0x8000, 0x8000);
		VirtualFree((void *)data, 0, release);
	}

	PT_TRASH(data);
}