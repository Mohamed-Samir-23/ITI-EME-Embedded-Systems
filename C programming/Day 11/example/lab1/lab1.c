#include <stdio.h>
#include <stdlib.h>

typedef struct node_t node;

struct node_t
{
	int data;
	node * next;	
};


typedef struct
{
	node * top;
}Stack;





node* creatNode(int data);
Stack* creatStack(void);
void push(Stack **q, int data);
int pop(Stack **q);
int isEmpty(Stack *q);
int peek(Stack *q);
void printStack(Stack *q);


int main(void)
{
	emp.x=5;
	int opration;
	Stack*s1=creatStack();
	while(opration!=4)
	{
		printf("program :\n");
		printf("to push enter 0 :\n");
		printf("to pop enter 1 :\n");
		printf("to peak enter 2 :\n");
		printf("to print stack enter 3 :\n");
		printf("to end program enter 4 :\n");
		scanf("%d",&opration);
		int data_enter=0,data_local=0,peek_local=0;
		switch(opration)
		{
			case 0: printf("enter number to store: ");
					scanf("%d",&data_enter);
					push(&s1, data_enter);
					break;	
			
			case 1: if(isEmpty(s1)==0)
					{
						data_local = pop(&s1);
						printf("pop = %d\n",data_local);
					}
					else
					{
						printf("the stack is empty\n");
					}
					break;
			case 2: if(isEmpty(s1)==0)
					{
						peek_local=peek(s1);
						printf("peek = %d\n",peek_local);
					}
					else
					{
						printf("the stack is empty\n");
					}
					break;			
			case 3: printStack(s1); 
					break;		
			case 4:	printf("the program is end\n");
					break;
			default:printf("this command not avalible \n");
					break;
		}
		
	}
	
	return 0;
}


node* creatNode(int data)
{
	node * newNode =(node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->next=(void *)0;
	return newNode;
}
Stack* creatStack(void)
{
	
	Stack*s1 = (Stack *)malloc(sizeof(Stack));
	s1->top=(void *)0;
	
}
void push(Stack **s, int data)
{
	node *newNode =creatNode(data);
	if(1==isEmpty(*s))
	{
		(*s)->top=newNode;
	}
	else
	{
		newNode->next=(*s)->top;
		(*s)->top=newNode;	
	}
	
}
int pop(Stack **s)
{
	int ret=-1;
	if(1==isEmpty(*s))
	{
		ret=-1;
	}
	else
	{
		node * temp = (*s)->top;
		ret=(*s)->top->data;
		(*s)->top=temp->next;
		free(temp);
		
	}
	
	return ret;
}
int isEmpty(Stack *s)
{
	int ret =-1;
	
	if(s->top==(void *)0)
	{
		ret =1;
		
	}
	else
	{
		ret =0;
		
	}
	return ret;
}
int peek(Stack *s)
{
	int ret =-1;
	
	if(1==isEmpty(s))
	{
		ret =-1;
	}
	else
	{
		ret =s->top->data;	
	}
	return ret;
}
void printStack(Stack *s)
{
	int i =1;
	while (s->top!=(void *)0)
	{
		printf("%d - > %d\n",i,s->top->data);
		s->top=s->top->next;
		i++;
	}
}


