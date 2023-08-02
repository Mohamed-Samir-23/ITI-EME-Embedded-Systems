#include <stdio.h>

int sum (int * x, int *y);
int main(void)
{
	int num1,num2,res;
	printf("please enter number 1: ");
	scanf("%d",&num1);
	printf("please enter number 2: ");
	scanf("%d",&num2);
	res=sum(&num1,&num2);
	printf("the sum of %d + %d = %d\n",num1,num2,res);
	return 0;
	
	
}


int sum (int * x, int *y)
{
	
	return (*x)+(*y);
}