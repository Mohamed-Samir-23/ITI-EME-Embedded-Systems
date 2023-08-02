#include <stdio.h>
void Bubble_Sorting(int arr[],int n);
int main(void)
{
	int arr1[4],i;
	for(i=0;i<4;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr1[i]);
	}
	Bubble_Sorting(arr1,4);
	
	printf("------------------\n");
	printf("sort:\n");
	for(i=0;i<4;i++)
	{
		printf("the arr[%d]= %d\n",i,arr1[i]);
		
	}
	
	return 0;
	
	
}



void Bubble_Sorting(int arr[],int n)
{
	int i,j,swap_flag=1,temp;
	for(i=0;(i<n)&&(swap_flag==1);i++) //9-4-7-2
	{
		swap_flag=0;
		for(j=0;j<(n-(1+i));j++)
		{
			if(arr[j]>arr[j+1])//
			{
				temp =arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap_flag=1;
			}
			else
			{
				
				
			}
			
		}
		
	}	
}