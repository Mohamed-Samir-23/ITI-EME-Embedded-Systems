#include <stdio.h>
int factoral(int num);
int main(void)
{
	int x =factoral(5);
	
	printf("%d",x);
	return 0;
	
	
}


int factoral(int num)
{
	int res =num;
	int rec;
	if (res==0)
	{
		rec= 1;
	}
	else
	{
		rec= res*factoral(res-1);
	}
	return rec;
}