#include <stdio.h>
#define x 10
int main(void)
{
	#if x==5
	int y =x;
	#elif x==6
		int y =6;
	#else
		int y =10;
	#endif
	printf("Hello World !");
	return 0;
	
}