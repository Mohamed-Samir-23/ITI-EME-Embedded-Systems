#include <stdio.h>
int main(void)
{
	
	int i,x,result=0;
	printf("enter the 10 numbers\n");
	for(i=0;i<10;i++)
	{
		printf("enter %d : ",i);
		scanf("%d",&x);
		result+=x;
	}
	printf("the sum is : %d\nthe average is :%f ",result,(float)result/10);
	return 0;
	
	
}