#include <stdio.h>
int main(void)
{
	int ids[3]={1234,5678,9870};
	int pass[3]={7788,5566,1122};
	char *str[] ={"Ahmed","Amr","wael"};
	int id_u,pass_u,i,ck=0,j=0,id_index_save;
	
	printf("please enter your ID: ");
	scanf("%d",&id_u);
	for(i=0;i<3;i++)
	{
		if(ids[i]==id_u)
		{
			ck=1;
			id_index_save=i;
			break;
		}
		else
		{
			
		}
	}
	if(ck==0)
	{
		printf("You are not registered\n");
	}
	else
	{
		do
		{
			printf("please enter your password: ");
			scanf("%d",&pass_u);
			if(pass[id_index_save]==pass_u)
			{
				printf("welcom %s",str[id_index_save]);
				break;
			}
			else
			{
				j++;
				if(j==3)
				{
					printf("no more try \n");
				}
				else
				{
					printf("try again\n");
				}
				
				
			}
		}while(j<3);
	}
	
	return 0;
	
	
}