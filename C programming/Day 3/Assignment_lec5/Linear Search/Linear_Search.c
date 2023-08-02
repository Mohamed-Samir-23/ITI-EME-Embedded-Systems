#include <stdio.h>
#define array_size 10
int linear_search(int arr[],int n,int sarch_num);
int main(void)
{
	
	int arr[array_size];
	int i,u32_search,u32_index;
	for(i=0;i<10;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr[i]);
	}
	printf("enter the the number to search : ");
	scanf("%d",&u32_search);
	
	u32_index =linear_search(arr,array_size,u32_search);
	if(u32_index==-1)
	{
		printf("the number is not exist");
	}
	else
	{
		printf("the number is exist and index is %d",u32_index);
	}
	return 0;
	
	
}



int linear_search(int arr[],int n,int sarch_num)
{
	
	int res=-1,i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==sarch_num)
		{
			res=i;
		}
		else
		{
			
		}
		
	}
		return res;
}