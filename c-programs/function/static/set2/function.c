
#include"abc.h"


static int func(int a, int b);
/*void  call(type funptr)
{
printf("Before function\n");
funptr(4,5);
printf("After function");
}


*/
type=func; 

 static int func(int a, int b)
{
        printf("add=%d\n",(a+b));

        return (a+b);
}

