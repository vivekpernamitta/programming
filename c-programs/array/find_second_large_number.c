/*

assiging lowest value to high,s_high
checking high first and low nest

2 3 5 4 1
^ ^ ^     --> if statment
^ ^   ^   --> lese if statement

*/


#include<stdio.h>
#include<limits.h>

void main()

{
	int i,j,high=0,s_high=0,s=0;
	int arr[10];
	printf("enter size of array max 10");
	scanf("%d", &s);
	for(i=0;i<s;i++)
	{
		scanf("%d",&arr[i]);
	}
	int high=s_high=INT_MIN;
	for (i=0;i<s;i++)
	{
		if( arr[i]> high)
		{
			printf("1st =  %d\n",arr[i]);

			s_high=high;
			high=arr[i];

		}
		else if (arr[i] > s_high)
		{	
			printf("second =   %d \n",arr[i]);
			s_high = arr[i];
		} 

	}

	printf("high= %d \n seconfd max =%d", high,s_high);
}

