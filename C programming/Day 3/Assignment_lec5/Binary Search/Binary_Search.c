#include <stdio.h>
void bb_sort
(
	int arr[],
	int n
);

void B_S
(
	int arr[],
	int n,
	int serch,
	int*ptr
);

int main(void)
{
	int i,u32_search;
	int arr1[10];//={5,6,8,15,44,66,12,13,99,1};
	for(i=0;i<10;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr1[i]);
	}
	
	
	bb_sort(arr1,10);
	printf("enter the the number to search : ");
	
	scanf("%d",&u32_search);
	
	printf("------------------\n");
	printf("sort:\n");
	for(i=0;i<10;i++)
	{
		printf("the arr[%d]= %d\n",i,arr1[i]);
		
	}
	
	B_S(arr1,10,u32_search,&i);
	
	if(-1==i)
	{
		printf("the number is not exist\n");
	}
	else
	{
		printf("the number is exist in index %d\n",i);
	}
	
	
	
	return 0;
	
	
}




void bb_sort
(
	int arr[],
	int n
)
{
	
	int i, j,flag_stop=1,temp;
	for(i=0;(i<(n-1))&&(flag_stop==1);i++)
	{
		for(j=0;(j<(n-1-i));j++)
		{
			flag_stop=0;
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag_stop=1;
			}
		}
		
	}
	
	
}


void B_S
(
	int arr[],
	int n,
	int serch,
	int*ptr
)
{
int top=0,bottom=(n-1),mid=0,flag=0;
*ptr=-1;
while(top<=bottom)
{
	mid=(top+bottom)/2;
	if(arr[mid]==serch)
	{
		*ptr=mid;
		break;
	}
	else if(serch>arr[mid])
	{
		top=mid+1;
	}
	else
	{
		bottom =mid-1;
	}
}
		
}