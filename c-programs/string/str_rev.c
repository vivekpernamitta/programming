/*#include<stdio.h>
  void main()
  {
  char string1[80]="this is string1",string2[80];
  int j,i;

//printf("enter the string");
//scanf("%80[^\n]",string1);
for(i=0,j=80;i<79;i++,j--)
{
string2[j]=string1[i];

}
string2[80]='\0';
printf("\n%s\n",string2);
}
 */
#include<stdio.h>
void main()
{
	int i, j, k;
	char str[100];
	char rev[100];
	printf("Enter a string\t");
	scanf("%100[^\n]", str);
	printf("The original string is=%s\n", str);
	for(i = 0; str[i] != '\0'; i++)
	{
		k = i;
	}
	for(j = 0; j < i ; j++)
	{
		rev[j] = str[k];
		k--;
	}
	printf("The reverse string is =%s\n", rev);
}
