#include <stdio.h>
int main(void)
{
	unsigned char x=255;
	signed char y=127;
	x++;
	y++;
	printf("x = %hhu\n",x);
	printf("y = %hhi\n",y);
	//printf("Hello World !");
	return 0;
	
	
}
/*

int x = 5;
int y =10;
if(++x>x++ && y-- > --y)
{
     printf("blablabla\n");
}
printf("%d\t %d",x,y);



*/