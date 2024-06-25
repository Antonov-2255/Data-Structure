//11. Write a program to insert a node at beginning of the doubly link
//list and delete a node at end of the doubly link list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next,*prev;
}*first,*ptr,*temp,*prev1;
void create();
void insert_begin();
void delete_end();
void display_frwd();
void display_bcwd();

void create()
{
	int n;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf(".....OVERFLOW.....");
		return;
	}
	printf("ENTER value of first node:");
	scanf("%d",&ptr->value);
	ptr->prev=NULL;
	first=ptr;
	x:
	printf("Do you want to enter more nodes if yes press 1 or press 2:");
	scanf("%d",&n);
	if(n==1)
	{
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter next node:");
		scanf("%d",&temp->value);
		ptr->next=temp;
		temp->prev=ptr;
		ptr=temp;
		goto x;
	}
	ptr->next=NULL;
}
void insert_begin()
{
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf(".....OVERFLOW.....");
		return;
	}
	printf("ENTER value of next node:");
	scanf("%d",&ptr->value);
	ptr->next=first;
	ptr->prev=NULL;
	first->prev=ptr;
	first=ptr;
}
void delete_end()
{
	if(first==NULL)
	{
		printf("....List is Empty....");
		return;
	}
	else
	{
		if(first->next==NULL)
		{
			printf("\n DELETED NODE IS %d",first->value);
			first=NULL;
			free(first);
		}
		else
		{
			temp=first;
			while(temp->next!=NULL)
			{
				prev1=temp;
				temp=temp->next;
			}
			prev1->next=NULL;
			printf("\n Deleted node is %d",temp->value);
			free(temp);
		}
	}
}
void display_frwd()
{
	if(first==NULL)
	{
		printf("....\nlink list is empty....");
		return;
	}
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			printf(" %d ",temp->value);
			temp=temp->next;
		}
	}
}
void display_bcwd()
{
	if(first==NULL)
	{
		printf("....\nlink list is empty....");
		return;
	}
	else
	{
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		while(temp!=NULL)
		{
			printf(" %d ",temp->value);
			temp=temp->prev;
		}
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\n1. Create");
		printf("\n2. insert_beginning");
		printf("\n3. Delete_ end");
		printf("\n4. Display forward");
		printf("\n5. Display backward");
		printf("\n6. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();break;
			case 2: insert_begin();break;
			case 3: delete_end();break;
			case 4: display_frwd();break;
			case 5: display_bcwd();break;
			case 6: exit(0);
			default: printf("\n Please enter a valid choice: between 1 to 6");
		}
	}
}
