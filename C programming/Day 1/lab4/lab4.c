#include <stdio.h>
int main(void)
{
	unsigned int x,y;
	printf("please enter number 1 : ");
	scanf("%d",&x);
	printf("please enter number 2 : ");
	scanf("%d",&y);
	printf("x&y = %d\n",x&y);
	printf("x|y = %d\n",x|y);
	printf("x^y = %d\n",x^y);
	printf("x>>1 = %d\n",(x>>1));
	printf("y<<2 = %d\n",(y<<2));
	return 0;
	
	
}