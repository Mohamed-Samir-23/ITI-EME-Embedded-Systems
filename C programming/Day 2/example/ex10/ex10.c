#include <stdio.h>
int main(void)
{
	int n;
	printf("enter number to display multplication table = ");
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=12;j++)
		{
			printf("%d x %d = %d \n",i,j,i*j);
		}
		printf("---------------------\n");
	}
	
	return 0;
	
	
}