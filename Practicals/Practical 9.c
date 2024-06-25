//9. Write a program to insert and delete node in singly link list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
}*first,*ptr,*prev,*temp;
void create();
void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
void display();

void create()
{
	int n;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("Enter first node:");
	scanf("%d",&ptr->value);
	first=ptr; // here ptr is treated as 1st node
	do
	{
		printf("\n Do you want to add more nodes?");
		printf("\n 1 for contitue...and 2 for discontinue..");
		scanf("%d",&n);
		if(n==1)
		{
			temp=(struct node*)malloc(sizeof(struct node*));
			printf("Enter next node:");
			scanf("%d",&temp->value);
			ptr->next=temp;
			ptr=temp;//ptr always pointed to last node
		}
		else if(n==2)
		{
			ptr->next=NULL;
			//exit(0);
		}
	}while(n!=2);
}
void insert_begin()
{
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("...OVERFLOW...");
		return;
	}
	else
	{
		printf("Enter new node:");
		scanf("%d",&ptr->value);
		ptr->next=first;
		first=ptr; // here ptr is treated as 1st node
	}
}
void insert_end()
{
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("...OVERFLOW...");
		return;
	}
	else
	{
		printf("Enter new node:");
		scanf("%d",&ptr->value);
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;// PTR will be treated as a last node
	}
}
void delete_begin()
{
	if(first==NULL)
	{
		printf("....UNDERFLOW....");
		return;
	}
	else
	{
		ptr=first;
		printf("\n DELETED NODE value is %d",ptr->value);
		first=first->next;
		free(ptr);
	}
}
void delete_end()
{
	if(first==NULL)
	{
		printf("....UNDERFLOW....");
		return;
	}
	else
	{
		if(first->next==NULL)
		{
			ptr=first;
			printf("\n DELETED NODE value is %d",ptr->value);
			first=first->next;
			free(ptr);
		}
		else
		{
			temp=first;
			while(temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			printf("\n DELETED NODE value is %d",temp->value);
			prev->next=NULL;
			free(temp);
		}
	}
}
void display()
{
	if(first==NULL)
	{
		printf("....\n Link list is empty....");
		return;
	}
	else
	{
			temp=first;
			while(temp!=NULL)
			{
				printf("%d ",temp->value);
				temp=temp->next;
			}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n1. Create");
		printf("\n2. Insert_beginning");
		printf("\n3. Insert _ end");
		printf("\n4. Delete from begin");
		printf("\n5. Delete from end");
		printf("\n6. display");
		printf("\n7. Exit");
		printf("\n Enter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create(); break;
			case 2: insert_begin(); break;
			case 3: insert_end(); break;
			case 4: delete_begin();break;
			case 5: delete_end();break;
			case 6: display();break;
			case 7: exit(0);
			default: printf("\nPlease enter any valid choice:");
		}
	}while(1);
}
