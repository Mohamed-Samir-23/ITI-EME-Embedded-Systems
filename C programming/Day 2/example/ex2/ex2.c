#include <stdio.h>
int main(void)
{
	unsigned int a;
	printf("please enter your working hours: ");
	scanf("%d",&a);
	if(a>=50)
	{
		printf("your salary is %d\n",(a*50));
	}
	else
	{
		printf("your salary is %d\n",((a*50)-((a*50)/10)));
	}
	int x= 5;
	
	
	
	return 0;
	
	
}