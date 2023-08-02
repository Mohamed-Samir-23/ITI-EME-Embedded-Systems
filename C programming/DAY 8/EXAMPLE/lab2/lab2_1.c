#include <stdio.h>
#include <stdlib.h>
typedef struct node_t node;
struct node_t
{
	int data;
	int key;
	node * tail;
};
void add_node(node ** head ,int data,int key);
void printList(node *ptr);
void deleteList(node **ptr,int key);
node * add_node2(node * head,int data,int key);
node * deleteList2(node *ptr,int key);
int main(void)
{
	int opration;
	node*head=(void *)0;
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
					//add_node(&head, data_enter,key_enter);
					head=add_node2(head,data_enter,key_enter);
					break; 
			case 1: printList(head); 
					break;
			case 2: printf("enter key you need to delete :\n");
					scanf("%d",&key_enter);
					//deleteList(&head,key_enter);
					head=deleteList2(head,key_enter);
					break;
			case 3:	printf("the program is end\n");
					break;
			default:printf("this command not avalible \n");
					break;
		}
		
	}
	
	
	
	return 0;
	
	
}



void add_node(node ** head_fun ,int data,int key)
{
	node * newnode =((void *)0);
	newnode=(node *)malloc(sizeof(struct node_t));
	newnode->data = data;
	newnode->key = key;
	newnode->tail = ((void *)0);
	
	if((*head_fun)!=((void *)0))
	{
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
	
	
}

void printList(node *ptr)
{
	printf("printlist : \n");
	while(ptr != (void *)0)
	{
		printf("data = %d  key = %d\n", ptr->data,ptr->key);
		ptr = ptr->tail;
	}
}




void deleteList(node **ptr,int key)
{
	
	node * previous_node =(void *)0;
	node * current_node =*ptr;
	node * temp_node =(void *)0;
	while(current_node->tail!=(void *)0)
	{
		if(current_node->key==key)
		{
			break;
		}
		else
		{
			previous_node= current_node;
			current_node=current_node->tail;
		}
		
		
	}
	if(current_node->tail!=(void *)0)
	{
		
		if((*ptr)->key==key)
		{
			temp_node=*ptr;
			*ptr=(*ptr)->tail;
			free(temp_node);
		}
		else
		{
			previous_node->tail = current_node ->tail;
			free(current_node);
		}
		
	}
	else
	{
		printf("the key not exist\n");
	}
	
	
}


node * add_node2(node * head,int data,int key)
{
	
	node * newnode =((void *)0);
	newnode=(node *)malloc(sizeof(struct node_t));
	newnode->data = data;
	newnode->key = key;
	newnode->tail = ((void *)0);
	
	if(head!=(void *)0)
	{
		node * temp_node =head;
		while(temp_node->tail!=(void *)0)
		{
			temp_node=temp_node->tail;
			
		}
		temp_node->tail=newnode;
		
		newnode=head;
	}
	else
	{
		
	}
	
	return newnode;
	
}

node * deleteList2(node *ptr,int key)
{
	
	node * previous_node =(void *)0;
	node * current_node =ptr;
	node * temp_node =(void *)0;
	while(current_node->tail!=(void *)0)
	{
		if(current_node->key==key)
		{
			break;
		}
		else
		{
			previous_node= current_node;
			current_node=current_node->tail;
		}
		
		
	}
	if(current_node->tail!=(void *)0)
	{
		
		if(ptr->key==key)
		{
			temp_node=ptr;
			ptr=ptr->tail;
			free(temp_node);
		}
		else
		{
			previous_node->tail = current_node ->tail;
			free(current_node);
		}
		
	}
	else
	{
		printf("the key not exist\n");
	}
	
	return ptr;
}