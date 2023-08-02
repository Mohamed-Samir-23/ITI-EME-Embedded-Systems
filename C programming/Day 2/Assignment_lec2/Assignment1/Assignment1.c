#include <stdio.h>
int main(void)
{
	
	int arr[10],i,src,j=0;
	for(i=0;i<10;i++)
	{
		printf("please enter number %d: ",i);
		scanf("%d",&arr[i]);
	}
	i=0;
	printf("please enter search number: ");
	scanf("%d",&src);
	
	while((i+1)!=11)
	{
		if(arr[i]==src)
		{
			printf("the search number is exist\n"); 
			break;
		}
		else if (i==9)
		{
			printf("the search number is not exist\n"); 
			break;
		}
		else
		{
			i++;
		}
		
	}
	
	return 0;
	
	
}