

typedef int (*type)(int,int);
void  call(type funptr)
{
printf("Before function\n");
funptr(4,5);
printf("After function");
}

