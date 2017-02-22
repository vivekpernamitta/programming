#include<stdio.h>
#include<stdlib.h>
#define LABEL 10

typedef struct box{
	int num;
	char *label;
	struct box *next;
}desk;

int i;

desk * create(int , int);
desk * traverse_fun();

desk *head,*tail,*traverse;

void main()
{
	int decision;
	while(1)
	{
		printf("Enter decision \n \
				1- Create list \n\
				2- traverse list \n\
				3- add a node at particular point \n\
				4- delete a node \n\
				10-exit \n");
		scanf("%d",&decision);
		switch (decision)
		{
			case 1:
				printf("You have opted for creating alist\n");
				create(1,2);
				break;
			case 2:
				printf(" you have opted for traversing a list\n");
				traverse_fun();
				break;
			case 10:
				break;

			default:
				printf("You have entered invalid option\n");
				break;
		}

	}
}

desk* create(int a,int b)
{

	head=NULL;
	traverse=NULL;
	int value=0,i;
	printf("  Enter the number of nodes you want to enteri\n");
	scanf("%d",&value);

	for(i=0;i<value;i++)
	{
		if(head==NULL)
		{
			head =(desk*)malloc(sizeof(desk));
			head->label=(char *) calloc(LABEL,1);
			printf("Enter num and label=");
			scanf("%d %s",&head->num,head->label);
			head->next=NULL;
			traverse=head;
			tail=head;
		}
		else
		{
			tail =(desk*)malloc(sizeof(desk));
			tail->label=(char *) calloc(LABEL,1);

			printf("\nEnter num and label\n");
			scanf("%d %s",&tail->num,tail->label);
			tail->next=NULL;

			traverse->next=tail;
			traverse=tail;

		}
	}
}

desk * traverse_fun()
{
	traverse=head;
	printf("NOW traversing the list\n");
	while(traverse!=NULL)
	{
		printf("The desk number=%d\t label=%s\n",traverse->num,traverse->label);
		traverse=traverse->next;
	}


}





