#include<stdio.h>

static int func(int a, int b);

int (*funptr)(int, int);


void main()
{

int ret_val;
	funptr=func;
        call(func);
	printf("the  ret_val=%d",ret_val);

}


static int func(int a, int b)
{
	printf("add=%d\n",(a+b));

	return (a+b);
}
