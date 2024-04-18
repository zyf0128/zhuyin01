#include<stdio.h>

int main()
{
#ifdef DEBUG
	printf("DEBUG:\n");
#else
	printf("Normal:\n");
#endif
	for(int i=0;i<3;i++)
		printf("work\n");
	return 0;
}
