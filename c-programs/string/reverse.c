#include<stdio.h>
#include<stdlib.h>

#define string1 IPSTR
#define string2 OPSTR

//int size;
typedef int (* size)(char *);
static int size_of_string(char *);
static char * string_reverse(char *,size ,char*);
static char * string_pattern(char *,size ,char* );
static char * string_replace(char *,size ,char*);


void main()
{
	char *string1=malloc(BUFSIZ);
	char *string2=malloc(BUFSIZ);
	char *cpy_err;

	printf(" enter the string : ");

	cpy_err=calloc(BUFSIZ,1);
	scanf("%48[^\n]s",string1);

	//	size=size_of_string(string1);     // to find length of string

	size str_size=size_of_string;     // assiging function pointer

	int choice=0;
	printf(" \	
			enter-1: Length of string\n \
			enter-2: string reverse\n \
			enter-3: To find the pattern in staring\n  \
			enter-4: To replace the word with the new word\n \
			");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Choice entered for length of string\n");
			int size=size_of_string(string1);
		case 2:
			printf("choice entered to reverse a string");
			string_reverse(string1, str_size, string2);
			break;
		case 3:
			printf("choice entered to find a patternin string");
			printf("enter the pattern you want to find\n");
			scanf("%s",string2);
			string_pattern(string1,str_size,string2);
			break;

		case 4:
			printf("Chioce entern to replace the pattern with the new string\n");
			//			string_replace(string1,str_size,string2);
			break;

		default : 
			printf("incorrect option entered :\n");
			break;



			printf("%s\n",cpy_err);
			//for(i=0;i<
	}
}

int size_of_string(char *string)
{
	int count=0;
	while(*string!='\0')
	{
		count++;
		string++;
	}

	printf("\nthe size sring is=%d\n",count);
	return (count);
}


char * string_reverse(char * string1, size str_size, char * string2)
{

	int count=str_size(string1);
	int i;
	char *temp_string1=string1;		// base address iof strng1 for sequence 
	string1=string1+count-1;		// pointer address to zero no count-1 is required
	printf("addressof string1=%p\n",string1);	
	char * temp=string2;			// when string2 is incremented base address is gone so back up
	printf("addressof string2=%p\n",string2);	
	for(i=count;i>0;i--)
	{
		*string2=*string1;
		printf(" loop: string1=%c\t string2=%c\taddressof string2=%p\n",*string1,*string2,string2);	
		if(string1==temp_string1)
		{
			*++string2='\0';
			break;
		}
		else{

			string1--;
			string2++;
		}
	}
	//		*++string2='\0';
	string2=temp;
	str_size(string2);
	printf("the reverse string1==%s and \t string2=%s\n",string1,string2);
	printf("addressof string2=%p\n",string2);	
	return string2;
}

char * string_pattern(char * string1, size str_size , char * string2)
{

	int i=0,j=0,count=0;
	int count_2=str_size(string2);
	char * temp=string2;
	while(*string1 != '\0')
	{
		j=0;
		int c2_val=count_2;
		if( *string1 == *string2 )	
		{
		
			for ( j=0; j<count_2; j++ )
			{
				if ((*string1 == *string2))
				{	
					if(*string1 == ' ' || *string2 == ' ')
					{
						string2=temp;	
						break;	
					}
					string1++;
					string2++;
					count++;
				}
				else
				{
					string2=temp;	
					break;
				}
			}

		}
		if (j==(count_2))
		{
			printf(" String found");
			string2=temp;
		}
		
			string1++;
	}
}






