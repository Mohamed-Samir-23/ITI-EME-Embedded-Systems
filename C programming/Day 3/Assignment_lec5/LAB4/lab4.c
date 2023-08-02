#include <stdio.h>
void lab4_liner
(
int arr[],
int n,
int serch,
int*ptr
);
int main(void)
{
	int arr1[10],i,u32_search;
	for(i=0;i<10;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr1[i]);
	}
	
	printf("enter the the number to search : ");
	scanf("%d",&u32_search);
	
	lab4_liner(arr1,10,u32_search,&i);
	if(0==i)
	{
		printf("the number is not exist");
	}
	else
	{
		printf("the number is exist %d times",i);
	}
	
	
	
	return 0;
	
	
}


void lab4_liner
(
int arr[],
int n,
int serch,
int*ptr
)
{
	
	int i;
	*ptr=0;
	for(i=0;i<n;i++) //9-4-7-2
	{
		if(serch==arr[i])
		{
			*ptr+=1;
		}
		else
		{
			
		}
	}
	
}
