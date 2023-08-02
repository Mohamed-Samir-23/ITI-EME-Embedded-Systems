#include <stdio.h>
void str_len(char*p,int * n);
int main(void)
{
	int ind;
	char *ptr ="Hello World !";
	str_len(ptr,&ind);
	
	printf("the length = %d\n",ind);
	return 0;
	
	
}




void str_len(char *p,int * n)
{
	
	*n=0;
	while((*p)!='\0')
	{
		*n+=1;
		p++;
	}
	if(*n==0)
	{
		*n=-1;
	}
	else
	{
		
	}
	
	
}