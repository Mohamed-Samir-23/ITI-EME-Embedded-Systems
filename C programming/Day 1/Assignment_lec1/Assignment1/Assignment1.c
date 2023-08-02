#include<stdio.h>
int main (void)
{
	int n;
	printf("enter number : ");
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		
		for(j=1;j<=(n+i);j++)
		{
			
			if(j<=(n-i-1))
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
			
		}
		
		printf("\n");
	}
}