#include <stdio.h>
void swap_ur(void);
int x=10,y=20;

int main(void)
{
	
	printf("x before swap = %d\n",x);
	printf("y before swap = %d\n",y);
	swap_ur();
	printf("x after swap = %d\n",x);
	printf("y after swap = %d\n",y);
	
	return 0;
	
	
}

void swap_ur(void)
{
	int temp =x;
	x=y;
	y=temp;
}