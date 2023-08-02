#include <stdio.h>
int main(void)
{
	
	unsigned int id;
	printf("please enter your id : ");
	scanf("%d",&id);
	switch(id)
	{
		printf("welcom x");
		volatile int x=5;
		default:printf("wrong ID");break;
		case 1234:printf("welcom Ahmed");break;
		case 5678:printf("welcom Youssef");break;
		case 1145:printf("welcom mina");break;
		case 5:printf("%d",x);
	}
	return 0;
	
	
}