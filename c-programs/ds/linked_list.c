#include<stdio.h>
#include<stdlib.h>
// this is structure template
struct node{
	char *name;
	int age;
	struct node *link;
	};

	typedef struct node details;

struct node *vi,book[2],*first,*last,*def=NULL,*ref;

int (*func[10])(details *ref,int);			// function pinter declatarion
int add(details *ref,int size);
int traverse(details *first, int size);
int add_after(details *first, int);
int del_after(details *, int);


enum options{create,del,sub,search};		// enum for entering options

	// add_pos the position you want  to add
	// add is function to create linked list
	// traverse is function the traers linked list
	// add-after is function that gooes to function routine





void main()
	{
	enum options opt;
	int value,sizes;
	char jump[3],*enumval;
	enumval=malloc(12);
	//printf("\nvalue in def=%p",def);
	//printf("\naddress of def=%p",&def);
		
	int i;
	for(i=0;i<3;i++)
	{

	printf("enter where to go");
	scanf("%d",&value);
	switch (value)
		{
		case 1:
			{	printf("Enter the numeber of noder you want\n");
				scanf("%d",&sizes);
				printf("You have created=%d nodes to create",sizes);
				//add(sizes);
				func[0]=&add;
				(*func[0])(ref,sizes);
			
				break;
			}
		case 2:
				printf("Now stiring will traverse now");
				func[1]=traverse;
				func[1](first,sizes);
				break;

		case 3 :
				printf(" where you want to enter the node\n");
				int add_pos;
				scanf("%d",&add_pos);
				func[2]=&add_after;
				func[2](first,add_pos);
				break;

		case 4 :
				printf("where you want to delelte a node:");
				int del_pos;
				scanf("%d",&del_pos);
				func[3]=&del_after;
				func[3](first,del_pos);
				
				
		case 10:      break;
		}	
	}

	//printf("enter the number of elements to include in linked list");
	//scanf("%d",size);


	//int q=(def+1);

	//printf("enter the degtails in book name and age\n");
	//char *vivek;
	//char *a=(char*)malloc(6);
	//vivek=a;
	//scanf("%s",vivek);
	//printf("name=%s sizeof name=%d",vivek,sizeof(vivek));

	//scanf("%s",&book[1].name);
	//scanf("%d",&book[1].age);
	//printf("/n the name =%s and age=%d",book[1].name,book[1].age);
	}

int add(details *ref,int size)
	{
	printf("function has entered\n");
	int i;
	for(i=0;i<size;i++)
			{
			if((ref)==NULL)
				{
				ref=malloc(sizeof(struct node));
				ref->name=malloc(10);
				printf("enter the name and age \n");			// enter name and age
				scanf("%s %d",ref->name,&ref->age);
				printf("\n the name you have entered=%s and \tage=%d",ref->name,ref->age);					
				
				ref->link=NULL;
				first=ref;
				last=ref;
				}	
			else
				{
				ref=malloc(sizeof(struct node));
				ref->name=malloc(10);

				printf("enter the name and age \n");			// enter name and age
				scanf("%s %d",ref->name,&ref->age);
				printf("\n the name you have entered=%s and \tage=%d",ref->name,ref->age);					

				last->link=ref;
				ref->link=NULL;
				last=ref;
				}
			}
	//return ref;
	}

int traverse(details *first, int size)
	{
	printf("now loop is traversed till end\n");
	struct node *traverse;
	traverse=first;
	ref=first;
	int mem;
	while((traverse)!=NULL)
		{
		printf("the node is traversing name=%s \t age=%d",traverse->name,traverse->age);
		traverse=traverse->link;
		//traverse=ref;
		}
	}

int add_after(details *start, int add_pos)
	{
	printf("function entered to add a node/n");
	int ref_pos=add_pos,i;
	ref=first;
	for(i=1;i<=add_pos;i++)
	{	
		if(ref_pos==i)
		{

		def=malloc(sizeof(details));
		def->name=malloc(10);
		printf("enter the name and age in the new node:\n");
		scanf("%s\t%d",def->name,&def->age);
		def->link=ref->link;
		ref->link=def;
		}
		else
	
		{
		ref=ref->link;
		}	

	}
	}

int del_after(details *first, int del_pos)
	{
	
	int ref_pos=del_pos+1,i;
	ref=first;
	if(del_pos==0)
		{
		first=ref->link;
		first=ref;
		}
	else
	{
		for(i=1;i<=del_pos;i++)
		{
		if(i==(del_pos))
			{
			details *alpha=ref;
			ref=ref->link;
			alpha->link=ref->link;
		
			}
		else
		ref=ref->link;
		}

	}	
	}
