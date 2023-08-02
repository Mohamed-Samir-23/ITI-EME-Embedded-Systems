#include <stdio.h>
void bblsort(int arr[],int length);
int binarySearch(int arr[],int length ,int search);
int main(void)
{
	
	int arr[8],i,srch,index;
	for(i=0;i<8;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr[i]);
	}
	
	bblsort(arr,8);
	printf("------------------\n");
	for(i=0;i<8;i++)
	{
		printf("enter the arr[%d]= %d\n",i,arr[i]);
		
	}
	printf("enter the number search about ");
	scanf("%d",&srch);
	index=binarySearch(arr,8 ,srch);
	if(index !=-1)
	{
		printf("the number is exist in index [%d]",index);
	}
	else
	{
		printf("the number is not exist");
	}
	return 0;
	
	
}

void bblsort(int arr[],int length)
{
	int i,j,swapflag=1;
	for(i=0;i<(length-1)&&(swapflag==1);i++)
	{
		swapflag=0;
		for(j=0;j<length-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp =arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapflag=1;
			}
			else
			{
				
			}
		}
	}
	
}

int binarySearch(int arr[],int length ,int search)
{
	int top =(length-1),bot=0,mid=(top+bot)/2,res=-1;
	while(top>=bot)
	{
		mid=(top+bot)/2;
		if(search==arr[mid])
		{
			res=mid;
		}
		else if (search>arr[mid])
		{
			bot=mid+1;
		}
		else
		{
			top=mid-1;
		}
	}
	return res;
}