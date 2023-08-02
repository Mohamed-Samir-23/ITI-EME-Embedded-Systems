#include <stdio.h>
int max_ur(int x,int y);
int main(void)
{
	int num1,num2,num3;
	printf("please enter number 1: ");
	scanf("%d",&num1);
	printf("please enter number 2: ");
	scanf("%d",&num2);
	printf("the maximum value is %d",max_ur(num1,num2));
	return 0;	
}
int max_ur(int x,int y)
{
	int res;
	if(x>=y)
	{
		res=x;
	}
	else
	{
		res=y;
	}
	return res;
}

