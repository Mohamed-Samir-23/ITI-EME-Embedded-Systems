#include <stdio.h>
#include "std_type.h"
int main(void)
{
	
	printf("unsigned char size %d byte\n",sizeof(u8));
	printf("unsigned short int size %d byte\n",sizeof(u16));
	printf("unsigned long int size %d byte\n",sizeof(u32));
	printf("unsigned long long int size %d byte\n",sizeof(u64));
	printf("signed char size %d byte\n",sizeof(s8));
	printf("signed short int size %d byte\n",sizeof(s16));
	printf("signed long int size %d byte\n",sizeof(s32));
	printf("signed long long int size %d byte\n",sizeof(s64));
	printf("float size %d byte\n",sizeof(f32));
	printf("double size %d byte\n",sizeof(f64));
	//printf("long double size %d byte\n",sizeof(long double));
	return 0;
	
	
}