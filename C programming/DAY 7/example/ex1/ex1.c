#include <stdio.h>
#include <stdlib.h>

int main()
{

   struct value
   {
       int bit1:1;
       int bit3:4;
       int bit4:4;
   }bit={1,2,13};
    //8421
    //1101
   //0000 0000 0000 0000 0000 0001 1010 0101
   printf("%d\n",sizeof(bit));
   printf("%u\n",bit.bit1);

	if(bit.bit1==1)
	{
	printf("hello");
	}

    return 0;
}