#include <stdio.h>
int main(void)
{
	unsigned int a;
	printf("please enter number 1 : ");
	scanf("%d",&a);
	if(a>=85)
	{
		printf("Excellent");
	}
	else if (a<85&&a>=75)
	{
		printf("very good");
	}
	else if (a<75&&a>=65)
	{
		printf("good");
	}
	else if (a<65&&a>=50)
	{
		printf("normal");
	}
	else
	{
		printf("failed");
	}
	return 0;
	
	
}