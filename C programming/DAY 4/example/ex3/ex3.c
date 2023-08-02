#include <stdio.h>
void func(int a ,int b ,int * ptr1,int * ptr2 );
int main(void)
{
	
	int a,b,sum,prod;
	printf("please enter number 1: ");
	scanf("%d",&a);
	printf("please enter number 2: ");
	scanf("%d",&b);
	func(a ,b,&sum,&prod);
	printf("the sum of %d + %d = %d\n",a,b,sum);
	printf("the prod of %d * %d = %d\n",a,b,prod);
	return 0;
	
	
}

void func(int a ,int b ,int * ptr1,int * ptr2 )
{
	*ptr1=a+b;
	*ptr2=a*b;
	
}