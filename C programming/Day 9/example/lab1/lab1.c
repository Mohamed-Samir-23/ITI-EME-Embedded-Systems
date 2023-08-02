#include <stdio.h>
#include <stdlib.h>
typedef struct node_t node;
struct node_t
{
	int data;
	int key;
	node * tail;
};
#define null (void *)0
node*head=null;
void add_node(int data,int key);
void printList(void);
void deleteList(void);

int main(void)
{
	
	int opration;
	
	while(opration!=3)
	{
		printf("program :\n");
		printf("to add node enter 0 :\n");
		printf("to print list enter 1 :\n");
		printf("to delete node enter 2 :\n");
		printf("to end program enter 3 :\n");
		scanf("%d",&opration);
		int data_enter=0,key_enter=0;
		switch(opration)
		{
			case 0: printf("enter number to store:\n");
					
					scanf("%d",&data_enter);
					printf("enter key to store:\n");
					scanf("%d",&key_enter);
					add_node(data_enter,key_enter);
					break; 
			case 1: printList(); 
					break;
			case 2: printf("the node is delete :\n");
					deleteList();
					break;
			case 3:	printf("the program is end\n");
					break;
			default:printf("this command not avalible \n");
					break;
		}
		
	}
	return 0;
	
	
}

void add_node(int data,int key)
{
	node * newnode =((void *)0);
	newnode=(node *)malloc(sizeof(struct node_t));
	newnode->data = data;
	newnode->key = key;
	newnode->tail = ((void *)0);
	if(head ==null)
	{
		head=newnode;
		
	}
	else
	{
		
		node *temp =head;
		while(temp->tail!=null)
		{
			temp=temp->tail;
		}
		temp->tail=newnode;
	}
	printf("the node is added\n");
}

void printList(void)
{
	printf("printlist : \n");
	node *temp =head;
	while(temp != (void *)0)
	{
		printf("data = %d  key = %d\n", temp->data,temp->key);
		temp = temp->tail;
	}
}


void deleteList(void)
{
	
	if(head ==null)
	{
		printf("the list is embty\n");
	}
	else
	{
		if(head->tail==null)
		{
			free(head);
			head=null;
		}
		else
		{
			node*temp=head;
			while((temp->tail)->tail!=null)
			{
				temp=temp->tail;
			}
			free((temp->tail)->tail);
			temp->tail=null;
		
		}
	}
	
	
	
}