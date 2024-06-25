//12. Write a program to insert an element at
//any position in doubly link list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next,*prev;
}*first,*ptr,*temp,*prev1;
void create();
void insert_pos();
void display_frwd();
void display_bcwd();


void create()
{
	int c;
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
	abc:
	printf("Do you want to enter more nodes if yes press 1 or press 2:");
	scanf("%d",&c);
	if(c==1)
	{
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter next node:");
		scanf("%d",&temp->value);
		ptr->next=temp;
		temp->prev=ptr;
		ptr=temp;
		goto abc;
	}
	ptr->next=NULL;
}
void insert_pos()
{
	int pos,i;
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf(".....OVERFLOW.....");
		return;
	}
	printf("\n Enter position:");
	scanf("%d",&pos);
	printf("ENter new node:");
	scanf("%d",&ptr->value);
	if(pos==1)
	{
		ptr->prev=NULL;
		ptr->next=first;
		first->prev=ptr;
		first=ptr;
	}
	else
	{
		temp=first;
		for(i=1;i<pos;i++)
		{
			if(temp->next==NULL)
			{
				printf("NO Node present at this position:");
				break;
			}
			else
			{
				prev1=temp;
				temp=temp->next;
			}
		}
		prev1->next=ptr;
		ptr->prev=prev1;
		ptr->next=temp;
		temp->prev=ptr;
	}
}
void display_frwd()
{
	if(first==NULL)
	{
		printf("....link list is empty....");
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
		printf("....link list is empty....");
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
		printf("\n2. insert_position");
		printf("\n3. Display forward");
		printf("\n4. Display backward");
		printf("\n5. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();break;
			case 2: insert_pos();break;
			case 3: display_frwd();break;
			case 4: display_bcwd();break;
			case 5: exit(0);
			default: printf("\n Please enter a valid choice: between 1 to 5");
		}
	}
}
