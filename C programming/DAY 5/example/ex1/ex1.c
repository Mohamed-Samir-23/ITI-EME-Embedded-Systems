#include <stdio.h>
int main(void)
{
	
	int x =5;
	int *ptr_x=&x;
	int **ptr=&ptr_x;
	printf("please enter number : ");
	scanf("%d",&x);
	printf("x = %d\n",x);
	**ptr=10;
	printf("x = %d\n",x);
	return 0;
		
}