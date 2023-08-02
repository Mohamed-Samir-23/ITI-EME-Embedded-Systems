#include <stdio.h>
int main(void)
{
	
	int n=1,r=1;
	printf("enter an integer : ");
	scanf("%d",&n);
	while(n)
	{
		r*=n;
		n--;
	}
	printf("the factorial = %d",r);

	return 0;
	
	
}