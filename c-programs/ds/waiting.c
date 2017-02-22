#include<stdlib.h>
#include<stdio.h>


typedef struct irctc{
char name[12];
int age;
struct irctc *node;
}irctc;


irctc *start,*stop,*ref=NULL,*adda;
int i;
int function1(int);

void main()
{
int count;
printf("enter the number of preple you want to create in waiting list");
scanf("%d",&count);
function1(count);
add();
function2(count);

}
int function1 (int count )
{
int a;
for(a=0;a<count;a++)
	{
	if (ref==NULL)
	{	ref=malloc(sizeof(struct irctc));
		printf("enter the name and age of passenger-1 \n");
		scanf("%s %d",ref->name,&ref->age); 
		printf("\n new line\n");
		start=ref;
		stop=ref;
		ref->node=NULL;
	}
	else
	{ 
		ref=malloc(sizeof(irctc));
		printf("enter the name and age of passengers-%d\n",(a+1));
		scanf("%s %d",ref->name,&ref->age);
		ref->node=NULL;
		stop->node=ref;
		stop=ref;
	}
	}	
return 0;
}



int function2(int count)
{
ref=start;
while((ref)!=NULL)
	{
	printf("\n name and age %s and %d",ref->name,ref->age);
	ref=ref->node;
	}
}






int add()
{
int a;
int count;
printf("\n where you wna tot enter node");
scanf("%d",&a);
ref=start;
count=a;
count;
for(i=1;i<=a;i++)
	{
	if((count)!=i)
		ref=ref->node;

	else	{
		  adda=malloc(sizeof(irctc));
                  printf("enter the name and age of passengers-%d\n",(a+1));
                  scanf("%s %d",adda->name,&adda->age);
                  adda->node=ref->node;
		  ref->node=adda;
		}
	
	}	

}

