#include <stdio.h>
int main(void)
{
	unsigned int x=6,y=5;
	if(x==6||y++)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
		printf("\n%d\n",y);//short circit 
	
	switch(x)
	{
		default:
		{
			printf("hi\n");
			//break;
		}
		case 5:
		{
			printf("noo\n");
			break;
		}
		case 6:
		
			printf("noo\n");
			printf("yoo\n");
			break;
		
	}
	
	x=5;
	x=++x + ++x ;
	//x+1 x=6
	//x+1 x=7 
	//return 7
	//x=7+7
	printf("x=%d\n",x);
	return 0;
	
	
}