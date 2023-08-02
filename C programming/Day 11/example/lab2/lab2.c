#include <stdio.h>


#define set_and_clear(reg, pin_need_to_change, value_change) do{ 	unsigned char tempreg =reg&~(pin_need_to_change);\
																	unsigned char mask =pin_need_to_change&value_change;\
																	reg=tempreg|mask;\
																}while(0)

#define pin0 0b00000001
#define pin1 0b00000010
#define pin3 0b00000100
#define output 0xff
														 
void print_bin(unsigned char value);
int main(void)
{
	
	unsigned char reg1= 0x00;
    unsigned char pins= pin3|pin0;//0b01001110  //
    unsigned char value=output;
	
    print_bin(reg1);
    set(reg1,pins,value);
    print_bin(reg1);
	return 0;
	
	
}



void print_bin(unsigned char value)
{
    int i;
    for (i = sizeof(char) * 7; i >= 0; i--)
        printf("%d", (value & (1 << i)) >> i );
        putc('\n', stdout);
}