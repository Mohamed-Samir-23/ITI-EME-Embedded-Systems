#include <stdio.h>
void Bubble_Sorting(void);
int main(void)
{
	
	
	Bubble_Sorting();
	
	return 0;
	
	
}



void Bubble_Sorting(void)
{
	int arr[10],i,j,swap_flag=1,temp;
	for(i=0;i<10;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;(i<10)&&(swap_flag==1);i++) //9-4-7-2
	{
		swap_flag=0;
		for(j=0;j<(10-(1+i));j++)
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
	printf("------------------\n");
	printf("sort:\n");
	for(i=0;i<10;i++)
	{
		printf("the arr[%d]= %d\n",i,arr[i]);
		
	}	
}