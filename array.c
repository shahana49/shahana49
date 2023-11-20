#include<stdio.h>
int main()
{	int i;
	int a[i];
	int total=0;
	int n;
	printf("enter the value of n:");
	scanf("%d",&n);

	if(n>0&&n<=50)
	{
		printf("enter the element in array:");
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			total=total+a[i];
		}
	printf("sum of numbers %d",total);
	}
	else if(n<0)
	{
	   printf("\n enter atleast one element");
	}	
	else
	{
	    printf("\n entered number is out of limit");
	}
	return(0);
	
}
