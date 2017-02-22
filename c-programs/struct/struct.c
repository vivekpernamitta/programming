#include<stdio.h>
char *p="aghjk";


struct test {
char *p;
};



struct list
{

int age,no;
char name;
//struct test junk;
}ball;



typedef struct list bick;
void main()
{


bick tall={
.age=21,

};


//ball.junk.p=malloc(10);
struct list  ball={
.age=22,
//.junk.p="vivek",
};

func(&ball);
printf("%d",ball.age);
//printf("\n%s",ball.junk.p);
printf("\n%d",sizeof((ball)));
printf("sample");
}

int func(struct list *doom){
doom->age=44;
printf("\nfunc%d",doom->age);
}
