#include <stdio.h>
int main(void)
{
	
	int arr[10],i,sum=0;
	float avr ;
	for(i=0;i<10;i++)
	{
		printf("please enter number %d: ",i);
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	avr =(float)sum/10;
	printf("-------------------------\n");
	for(i=9;i>=0;i--)
	{
		printf("arr[%d] = %d\n",i,arr[i]);	
	}
	printf("-------------------------\n");
	printf("the sum of array is %d\n",sum);
	printf("the average of array is %0.2f\n",avr);
	return 0;
	
	
}