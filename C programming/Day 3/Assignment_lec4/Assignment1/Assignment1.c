#include <stdio.h>
#include <stdarg.h>
int max_4_value(int n,...);
int min_4_value(int n,...);
int main(void)
{
	
	//printf("Hello World !");
	int i,num1,num2,num3,num4; 
	printf("please enter number 1: ");
	scanf("%d",&num1);
	printf("please enter number 2: ");
	scanf("%d",&num2);
	printf("please enter number 3: ");
	scanf("%d",&num3);
	printf("please enter number 4: ");
	scanf("%d",&num4);
	int max=max_4_value(4,num1,num2,num3,num4);
	int min =min_4_value(4,num1,num2,num3,num4);
	printf("the maximum value is %d\n",max);
	printf("the minimum value is %d\n",min);
	return 0;
	
	
}


int max_4_value(int n,...)
{
	int i,u32_max,u32_temp1;
	va_list ptr;
	va_start(ptr,n);
	
	
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			u32_max=va_arg(ptr,int);
		}
		else
		{
			u32_temp1=va_arg(ptr,int);
			if(u32_temp1>u32_max)
			{
				u32_max=u32_temp1;
			}
			else
			{
				
			}
		}
	}
	va_end(ptr);
	return u32_max;
}
int min_4_value(int n,...)
{
	int i,u32_max,u32_temp1;
	va_list ptr;
	va_start(ptr,n);
	
	
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			u32_max=va_arg(ptr,int);
		}
		else
		{
			u32_temp1=va_arg(ptr,int);
			if(u32_temp1<u32_max)
			{
				u32_max=u32_temp1;
			}
			else
			{
				
			}
		}
	}
	va_end(ptr);
	return u32_max;
}