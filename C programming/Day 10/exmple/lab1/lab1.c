#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	char * name;
	int id;
	int salary ;
}person;

typedef struct 
{
	int lic;
	char * color;	
}car;



typedef struct link
{
	
	void * data;
	struct link * next;
	
	
}node;

void addfrist(node ** head,void * data ,int size_data);
void print_genaric(node ** head,void(*ptrtofun)(void *));
void print_data_person (void * data);

int main(void)
{
	
	person f1={"ahmed",20,50};
	person f2={"ali",50,50};
	car C1={2021,"Toyota"};
	car C2={2023,"Bentley"};
	node *head=((void *)0);
	
	
	addfrist(&head,&f1,sizeof(person));
	addfrist(&head,&f2,sizeof(person));
	addfrist(&head,&C1,sizeof(car));
	addfrist(&head,&C2,sizeof(car));
	 
	print_genaric(&head,print_data_person);
	
	print_genaric(&head,print_data_car);
	return 0 ;
	return 0;
	
	
}


void addfrist(node ** head,void * data ,int size_data)
{
	
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=*head;
	int i ;
	for(i=0;i<size_data;i++)
	{
		*(((char *)newnode->data)+i)=*(((char *)data)+i);
	}
	*head=newnode;
	
}

void print_genaric(node ** head,void(*ptrtofun)(void *))
{
	node *temp=*head;
	
	while (temp !=((void *)0))
	{
		if()
		ptrtofun(temp->data);
		temp=temp->next;
	}
	
}



void print_data_person (void * data)
{
	printf("%s\n",((person *)data)->name);
	printf("%d\n",((person *)data)->id);
	printf("%d\n",((person *)data)->salary);
}

void print_data_car (void * data)
{
	printf("%d\n",((person *)data)->lic);
	printf("%s\n",((person *)data)->color);
}
