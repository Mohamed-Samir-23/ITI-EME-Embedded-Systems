#include <stdio.h>
#include <stdlib.h>

void bb_sort (char *ptr, int n);
int main(void)
{
	
	char x,i;
	printf("please enter number of bytes to allcated : ");
	scanf("%hhi",&x);
	
	void *ptr2=malloc(1);
	//*((char*)ptr2)=5;
	*ptr2=5;
	printf("%d",*((char*)ptr2));
	char *ptr=(char *)malloc(x);
	
	for(i=0;i<x;i++)
	{
		printf("enter the ptr[%d] ",i);
		scanf("%d",&ptr[i]);//(ptr+i)
	}
	bb_sort (ptr, x);
	printf("------------------\n");
	printf("sort:\n");
	for(i=0;i<x;i++)
	{
		printf("the arr[%d]= %d\n",i,ptr[i]);
		
	}
	
	return 0;
	
	
}



void bb_sort (char *ptr, int n)
{
	
	int i,j,swap_flag=1,temp;
	for(i=0;(i<n)&&(swap_flag==1);i++)
	{
		swap_flag=0;
		for(j=0;j<(n-(1+i));j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				temp =ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
				swap_flag=1;
			}
			else
			{
				
				
			}
			
		}
		
	}
	
	
	
}