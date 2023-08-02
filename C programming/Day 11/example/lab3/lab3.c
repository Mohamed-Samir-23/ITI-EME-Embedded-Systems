#include <stdio.h>
#define null ((void *)0) 
typedef struct node_t node

struct node_t
{
	int data;
	int key;
	node *left;
	node *right;
};
node * createNode(int data);
void insert_left(node**root,int data);
void insert_right(node**root,int data);
void preorder_tree(node * root);

int main(void)
{
	node*n1=null;
	insert_left(&n1,1);
	insert_left(&n1,2);
	insert_left(&n1,3);
	
	insert_left(&n1,3);
	insert_left(&n1,1);
	insert_left(&n1,1);
	insert_left(&n1,1);
	
	return 0;	
}


node * createNode(int data,int key)
{
	node*newNode=(node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->key=key;
	newNode->left=null;
	newNode->right=null;	
}

void insert_left(node**root,int data,int key)
{
	node * newNode=createNode(data,key);
	if((*root)==null)
	{
		*root=newNode;
	}
	else
	{
		node *temp =(*root);
		while(temp->left!=null)
		{
			temp =temp->left;
		}
		temp->left=newNode;
	}
	
}


void insert_right(node**root,int data)
{
	node * newNode=createNode(data);
	if((*root)==null)
	{
		*root=newNode;
	}
	else
	{
		node *temp =(*root);
		while(temp->right!=null)
		{
			temp =temp->right;
		}
		temp->right=newNode;
	}
	
}


void preorder_tree(node * root)
{
	if(null!=root)
	{
		printf("%d \t",root->data);
		preorder_tree(root->left);
		preorder_tree(root->right);
	}
	
	
}

