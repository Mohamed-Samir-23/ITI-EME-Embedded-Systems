#include <stdio.h>
int main(void)
{
	
	int x =10,*ptr;
	printf("x before change = %d\n",x);
	ptr=&x;
	*ptr=20;
	printf("x after change = %d\n",x);
	return 0;
	
	
}