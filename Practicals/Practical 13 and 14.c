//13. Write a program to create a binary search tree.
//14. Write a program for binary tree traversal in-order,
//    pre-order, post-order.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *lptr;
	struct node *rptr;
}*root=NULL,*temp;
void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->lptr);
		printf("%d ",root->key);
		inorder(root->rptr);
	}
}
void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->key);
		preorder(root->lptr);
		preorder(root->rptr);
	}
}
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->lptr);
		postorder(root->rptr);
		printf("%d ",root->key);
	}
}
struct node* newnode(int item)
{
	temp = (struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->lptr=NULL;
	temp->rptr=NULL;
	return temp;
}
struct node* insert(struct node* node,int key)
{
	if(node==NULL)

		return newnode(key);

	if(key<node->key)
	{

		node->lptr=insert(node->lptr,key);
		return node;
	}
	else
	{
		node->rptr=insert(node->rptr,key);
		return node;
	}
}
void main()
{
	int i,n,data;
	printf("Enter total number of nodes that you want to insert:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			printf("Enter root node value:");
			scanf("%d",&data);
			root=insert(root,data);
		}
		else
		{
			printf("Enter node value:");
			scanf("%d",&data);
			insert(root,data);
		}
	}
	printf("\nInorder Traversal:");
	inorder(root);
	printf("\n..........................................");
	printf("\nPreorder Traversal:");
	preorder(root);
	printf("\n..........................................");
	printf("\nPostorder Traversal:");
	postorder(root);
	printf("\n..........................................");
}
