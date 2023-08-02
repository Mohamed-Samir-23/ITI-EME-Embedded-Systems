#include <stdio.h>
#include <stdlib.h>
typedef struct node_t node;
struct node_t
{
	int data;
	node * tail;
};
void enqueue(node ** head_fun ,int data);
void printqueue(node *ptr);
int dequeue(node **ptr);
int peek(node *ptr);

int queue_number=0,size_of_queue=0;
int main(void)
{	
	int opration;
	node*head=(void *)0;
	printf("enter the size of queue:\n");
	scanf("%d",&size_of_queue);
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
			case 0: if(queue_number<size_of_queue)
					{
						printf("enter number to store:\n");
						scanf("%d",&data_enter);
						enqueue(&head, data_enter);
					}
					else
					{
						printf("the queue is full\n");
					}
					break;	
			
			case 1: if(queue_number!=0)
					{
						data_local = dequeue(&head);
						printf("dequeue = %d\n",data_local);
					}
					else
					{
						printf("the queue is empty\n");
					}
					break;
			case 2: peek_local=peek(head);
					printf("peek = %d\n",peek_local);
					break;			
			case 3: printqueue(head); 
					break;		
			case 4:	printf("the program is end\n");
					break;
			default:printf("this command not avalible \n");
					break;
		}
		
	}
	return 0;
}	
	
void enqueue(node ** head_fun ,int data)
{
	node * newnode =((void *)0);
	newnode=(node *)malloc(sizeof(struct node_t));
	newnode->data = data;
	newnode->tail = ((void *)0);
	
	if((*head_fun)!=((void *)0))
	{
		//newnode->tail=*head_fun;
		//*head_fun=newnode;
		node *temp =*head_fun;
		while(temp->tail!=((void *)0))
		{
			temp=temp->tail;
		}
		
		temp->tail=newnode;	
	}
	else
	{
		*head_fun=newnode;
	}
	
	queue_number++;
}
void printqueue(node *ptr)
{
	printf("print-queue : \n");
	while(ptr != (void *)0)
	{
		printf("data = %d\n", ptr->data);
		ptr = ptr->tail;
	}
}




int dequeue(node **ptr)
{
	int data=(*ptr)->data;
	node * temp_node =(void *)0;
	temp_node=*ptr;
	*ptr=(*ptr)->tail;
	free(temp_node);
	queue_number--;
	return data;
}

int peek(node *ptr)
{
	int data=ptr->data;
	return data;
}

