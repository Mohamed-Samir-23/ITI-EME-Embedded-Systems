#include <stdio.h>
int func (int *p,int n);
int main(void)
{
	
	int arr[10],i;
	for(i=0;i<10;i++)
	{
		printf("enter the arr[%d] ",i);
		scanf("%d",&arr[i]);
	}
	
	func (arr,10);
	
	return 0;
	
	
}


int func (int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("print arr[%d]= %d\n",i,*p);
		p++;
	}
		
}