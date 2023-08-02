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
	node * front;
	node * rear;
}queue;



node* creatNode(int data);
queue* creatQueue(void);
void enQueue(queue *q, int data);
int deQueue(queue *q);
int isEmpty(queue *q);
int peek(queue *q);
void printQueue(queue *q);

int main(void)
{
	
	int opration;
	queue *q1=creatQueue();
	while(opration!=4)
	{
		printf("program :\n");
		printf("to enqueue enter 0 :\n");
		printf("to dequeue enter 1 :\n");
		printf("to peak enter 2 :\n");
		printf("to print queue enter 3 :\n");
		printf("to end program enter 4 :\n");
		scanf("%d",&opration);
		int data_enter=0,data_local=0,peek_local=0;
		switch(opration)
		{
			case 0: printf("enter number to store: ");
					scanf("%d",&data_enter);
					enQueue(q1, data_enter);
					break;	
			
			case 1: if(isEmpty(q1)==0)
					{
						data_local = deQueue(q1);
						printf("dequeue = %d\n",data_local);
					}
					else
					{
						printf("the queue is empty\n");
					}
					break;
			case 2: if(isEmpty(q1)==0)
					{
						peek_local=peek(q1);
						printf("peek = %d\n",peek_local);
					}
					else
					{
						printf("the queue is empty\n");
					}
					break;			
			case 3: printQueue(q1); 
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

queue* creatQueue(void)
{
	
	queue * newQueue =(queue *)malloc(sizeof(queue));
	newQueue->front=(void *)0;
	newQueue->rear=(void *)0;
	return newQueue;
}
void enQueue(queue *q, int data)
{
	 
	node* newNode =creatNode(data);
	if(q->front==((void *)0))
	{
		q->front=newNode;
	}
	else
	{
		q->rear->next=newNode;
	}
	
	q->rear=newNode;
	
	
}
int deQueue(queue *q)
{
	int ret =-1;
	if(isEmpty(q)==1)
	{
		ret=-1;
	}
	else
	{
		node * temp =q->front;
		ret=temp->data;
		q->front=temp->next;
		free(temp);
		if(q->front==(void *)0)
		{
			q->rear = (void *)0;
		}
		else
		{
			
		}
		
	}
	
	return ret;
	
	
}
int isEmpty(queue *q)
{
	int ret=0;
	if(q->front==(void *)0)
	{
		
		ret=1;
		
	}
	else
	{
		
		ret=0;
	}
	return ret;
}
int peek(queue *q)
{
	int ret=-1;
	if(isEmpty(q)==1)
	{
		printf("the Queue is empty ");
		ret =-1;
	}
	else
	{
		ret= q->front->data;
	}
	
	return ret;
}
void printQueue(queue *q)
{
	if(isEmpty(q)==1)
	{
		printf("the Queue is empty\n");
		
	}
	else
	{
		int i =1;
		node * newNode=q->front;
		
		while(newNode!=(void *)0)
		{
			printf("node %d - %d\n",i,newNode->data);
			i++;
			newNode=newNode->next;
		}
	}
	
}