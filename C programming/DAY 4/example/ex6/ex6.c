#include <stdio.h>
#include <stdlib.h>

void fun (int x);

int main()
{

    printf("%p",10);
    void (*ptr)(int);
	printf("%p\n",fun);
    ptr=fun;
	printf("%p\n",ptr);
	(*ptr)(5);
    ptr(5);
	int arr [10]={1,2,3,4,5,6,7,8,9,10};
	printf("%p\n",arr);
	printf("%p\n",&arr);
	printf("%p\n",&arr[0]);
    return 0;
}


void fun (int x)
{
    printf("%d\n",x);
}
