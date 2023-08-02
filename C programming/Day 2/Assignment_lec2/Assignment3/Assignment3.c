#include <stdio.h>
int main(void)
{
	int num1,num2,num3,max;
	printf("please enter number 1: ");
	scanf("%d",&num1);
	printf("please enter number 2: ");
	scanf("%d",&num2);
	printf("please enter number 3: ");
	scanf("%d",&num3);
	if(num1>=num2)
	{
		if(num1>num3)
		{
			max=num1;
		}
		else
		{
			max=num3;
		}
	}
	else
	{
		if(num2>num3)
		{
			max=num2;
		}
		else
		{
			max=num3;
		}
		
	}
	printf("the max number is %d\n",max);
	return 0;
}