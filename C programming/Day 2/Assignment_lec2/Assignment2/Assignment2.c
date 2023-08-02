#include <stdio.h>
int main(void)
{
	int id_s,pass_s,id_u,pass_u;
	id_s=555;
	pass_s=250;
	while(1)
	{
	printf("please enter your id: ");
	scanf("%d",&id_u);
	if(id_u==id_s)
	{
		printf("the id is valid\n");
		printf("please enter number pass: ");
		scanf("%d",&pass_u);
		if(pass_u==pass_s)
		{
			printf("the password is correct\n");
			printf("hello mohamed samir\n");
			break;
		}
		else
		{
			printf("the password is incorrect\n");
		}
	}
	else
	{
		printf("the id is not valid\n");
	}
	}
	
	return 0;
	
	
}