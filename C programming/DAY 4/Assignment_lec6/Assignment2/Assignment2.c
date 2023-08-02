#include <stdio.h>
int main(void)
{
	int x=5,y=6,z=7;
	int *p=&x,*q=&y,*r=&z;
	
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	printf("z = %d\n",z);
	printf("p = %p\n",p);
	printf("q = %p\n",q);
	printf("r = %p\n",r);
	printf("*p = %d\n",*p);
	printf("*q = %d\n",*q);
	printf("*r = %d\n",*r);
	printf("Swapping pointers !\n");
	r = p;//x
	p = q; //y
	q = r; //x
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	printf("z = %d\n",z);
	printf("p = %p\n",p);
	printf("q = %p\n",q);
	printf("r = %p\n",r);
	printf("*p = %d\n",*p);
	printf("*q = %d\n",*q);
	printf("*r = %d\n",*r);
	return 0;
	
	
}