#include <stdio.h>
int main(void)
{
	int x=6;//110
	int result =x;

	if((x&1))
	{
		printf("odd way 1\n");
	}
	else
	{
		printf("even way 1\n");
	}
	
	if(x%2==0)
	{
		printf("even way 2\n");
	}
	else
	{
		printf("odd way 2\n");
	}
	if(x==((x/2)*2))
	{
		printf("even way 3\n");
	}
	else
	{
		printf("odd way 3\n");
	}
	result>>=1;
	result<<=1;
	if(result==x)
	{
		printf("even way 4\n");
	}
	else
	{
		printf("odd way 4\n");
	}
	
	
	//printf("%d\n",result);//110
	
	return 0;
	
	
}