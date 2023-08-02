#include <stdio.h>
int main(void)
{
	
	printf("enter the answer 3x4 = ");
	int ans=0;
	while(1)
	{
		scanf("%d",&ans);
		if(ans==12)
		{
			break;
		}
		else
		{
			printf("not correct please try again :  ");
		}
	}
	printf("Thank you");
	return 0;
	
	
}