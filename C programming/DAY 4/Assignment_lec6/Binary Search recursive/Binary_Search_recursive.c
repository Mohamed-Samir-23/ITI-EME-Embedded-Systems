#include <stdio.h>
void b_s_r (int *ptr ,int n ,int serch ,int * index,int mid);
int main(void)
{
	int in_dex=-1;
	int arr1[10]={5,6,8,15,44,66,12,13,99,1};
	b_s_r (arr1 ,10 ,66 ,&in_dex,0);
	
	printf("%d\n",in_dex,);
	return 0;
	
	
}



void b_s_r (int *ptr ,int n ,int serch ,int * index,int mid)// mid -- n 
{
	mid=(mid+(n-1))/2;
	
	int res;
	
	if(ptr[mid]==serch)
	{
		res=mid;
		
	}
	else if(ptr[mid]>serch)
	{
		res = b_s(ptr,mid-1,serch,index,mid);
	}
	else
	{
		res = b_s(ptr,n,serch,index,mid+1);
	}
	
	return 1;
}