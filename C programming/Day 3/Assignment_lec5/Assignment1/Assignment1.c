#include <stdio.h>

void min_max
(
	int arr[],
	int n,
	int*max,
	int*min
);

int main(void)
{
	
	int arr1[10],i,max_n,min_n;
	for(i=0;i<10;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr1[i]);
	}
	
	min_max(arr1,10,&max_n,&min_n);
	
	printf("the max number is = %d\n",max_n);
	printf("the min number is = %d\n",min_n);
	return 0;
	
	
}


void min_max
(
	int arr[],
	int n,
	int*max,
	int*min
)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(0==i)
		{
			*min=arr[0];
			*max=arr[0];
		}
		else
		{
			if((*max)<arr[i])
			{
				*max=arr[i];
			}
			else
			{
				
			}
			if((*min)>arr[i])
			{
				*min=arr[i];
			}
			else
			{
				
			}
		}
	}	
}