#include <stdio.h>
void class_p1
(
	int arr[],
	int n,
	int*passed_n,
	int*failed_n,
	int*Highest_n,
	int*Lowest_n
);
void class_average
(
	int arr[],
	int n,
	int*aver
);
int main(void)
{
	int i;
	int passed_1,failed_1,Highest_1,Lowest_1,Average1;
	int passed_2,failed_2,Highest_2,Lowest_2,Average2;
	int passed_3,failed_3,Highest_3,Lowest_3,Average3;
	
	int students_class1[10]={92,87,67,23,21,28,51,50,34,29};
	int students_class2[10]={36,90,67,66,39,43,83,75,85,20};
	int students_class3[10]={30,95,42,78,36,59,94,66,87,51};
	
	class_p1(students_class1,10,&passed_1,&failed_1,&Highest_1,&Lowest_1);
	class_p1(students_class2,10,&passed_2,&failed_2,&Highest_2,&Lowest_2);
	class_p1(students_class3,10,&passed_3,&failed_3,&Highest_3,&Lowest_3);
	
	class_average(students_class1,10,&Average1);
	class_average(students_class2,10,&Average2);
	class_average(students_class3,10,&Average3);
	
	
	printf("Number of passed students is %d\n",(passed_1+passed_2+passed_3));
	printf("Number of Failed students is %d\n",(failed_1+failed_2+failed_3));
	
	
	if(Highest_1>=Highest_2)
	{
		if(Highest_1>=Highest_3)
		{
			printf("the Highest grade is %d\n",Highest_1);
		}
		else
		{
			printf("the Highest grade is %d\n",Highest_3);
		}
	}
	else
	{
		if(Highest_2>=Highest_3)
		{
			printf("the Highest grade is %d\n",Highest_2);
		}
		else
		{
			printf("the Highest grade is %d\n",Highest_3);
		}
		
		
	}
	
	if(Lowest_1<=Lowest_2)
	{
		if(Lowest_1<=Lowest_3)
		{
			printf("the Lowest grade is %d\n",Lowest_1);
		}
		else
		{
			printf("the Lowest grade is %d\n",Lowest_3);
		}
	}
	else
	{
		if(Lowest_2<=Lowest_3)
		{
			printf("the Lowest grade is %d\n",Lowest_2);
		}
		else
		{
			printf("the Lowest grade is %d\n",Lowest_3);
		}
		
		
	}
	
	printf("the  Average grade is %d\n",(Average1+Average2+Average3)/3);
	
	return 0;
	
	
}


void class_p1
(
	int arr[],
	int n,
	int*passed_n,
	int*failed_n,
	int*Highest_n,
	int*Lowest_n
)
{
	*passed_n=0;
	*failed_n=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(0==i)
		{
			*Highest_n=arr[0];
			*Lowest_n=arr[0];
		}
		else
		{
			if((*Highest_n)<arr[i])
			{
				*Highest_n=arr[i];
			}
			else
			{
				
			}
			if((*Lowest_n)>arr[i])
			{
				*Lowest_n=arr[i];
			}
			else
			{
				
			}
			
			
		}
		if(arr[i]>=50)
		{
			(*passed_n)+=1;
		}
		else
		{
			(*failed_n)+=1;
		}
	}
	
}

void class_average
(
	int arr[],
	int n,
	int*aver
)
{
	
	*aver=0;
	int i;
	for(i=0;i<n;i++)
	{
		(*aver)+=arr[i];
	}
	
	(*aver)/=n;
	
}