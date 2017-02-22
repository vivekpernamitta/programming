#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int i;
	char * ptr;
	ptr=(char *)malloc(16);

	strcpy(ptr,"memory overload");

	printf("the data stored in ptr storage = '%s' \n ", ptr);
//	printf(" the size fo ptr = '%d' \n", sizeof(ptr));
}
