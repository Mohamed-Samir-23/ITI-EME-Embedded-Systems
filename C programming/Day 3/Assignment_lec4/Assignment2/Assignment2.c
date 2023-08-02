#include <stdio.h>
int main(void)
{
	int num1=0,num2=0,id=0;
	printf("Note:\n1-Add\n2-Subtract\n3-Multiply\n4-Divide\n");
	printf("5-And\n6-Or\n7-Not\n8-Xor\n");
	printf("9-reminder\n10-Increment\n11-Decrement\n");
	printf("please enter ID of opperation : ");
	scanf("%d",&id);
	if((id>=1)&&(id<7)||(id==9)||(id==9))
	{
		printf("please enter number 1: ");
		scanf("%d",&num1);
		printf("please enter number 2: ");
		scanf("%d",&num2);
	}
	else if (id==7||id==10||id==11)
	{
		printf("please enter number : ");
		scanf("%d",&num1);
	}
	else
	{
		printf("this id is not exist\n");
	}
	
	switch(id)
	{
		
		case 1:printf("%d + %d = %d\n ",num1,num2,Add_fun(num1,num2));break;
		case 2:printf("%d - %d = %d\n ",num1,num2,Subtract_fun(num1,num2));break;
		case 3:printf("%d * %d = %d\n ",num1,num2,Multiply_fun(num1,num2));break;
		case 4:printf("%d / %d = %d\n ",num1,num2,Divide_fun(num1,num2));break;
		case 5:printf("%d & %d = %d\n ",num1,num2,And_fun(num1,num2));break;
		case 6:printf("%d | %d = %d\n ",num1,num2,Or_fun(num1,num2));break;
		case 7:printf("%d ~ = %d\n ",num1,Not_fun(num1));break;
		case 8:printf("%d ^ %d = %d\n ",num1,num2,Xor_fun(num1,num2));break;
		case 9:printf("%d \% %d = %d\n ",num1,num2,reminder_fun(num1,num2));break;
		case 10:printf("%d + 1 = %d\n ",num1,Increment_fun(num1));break;
		case 11:printf("%d - 1 = %d\n ",num1,Decrement_fun(num1));break;
		default :break;
	}
	
	
	
	
	return 0;
}





int Add_fun(int x, int y)
{
	return x+y;
}

int Subtract_fun(int x, int y)
{
	return x-y;
}

int Multiply_fun(int x, int y)
{
	return x*y;
}

int Divide_fun(int x, int y)
{
	return x/y;
}

int And_fun(int x, int y)
{
	return x&y;
}

int Or_fun(int x, int y)
{
	return x&y;
}

int Not_fun(int x, int y)
{
	return ~x;
}

int Xor_fun(int x, int y)
{
	return x^y;
}

int reminder_fun(int x, int y)
{
	return x%y;
}

int Increment_fun(int x)
{
	return ++x;
}

int Decrement_fun(int x)
{
	return --x;
}