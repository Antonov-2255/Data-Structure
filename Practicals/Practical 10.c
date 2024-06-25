//10. Write a program to count the no. of node
//and searching the specific node in singly link list.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
}*first,*ptr,*prev,*temp;
void create();
void count_node();
void search_node();

void create()
{
	int ch;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("Enter first node:");
	scanf("%d",&ptr->value);
	first=ptr; // here ptr is treated as 1st node

	choice:
		printf("\n Do you want to add more nodes?");
		printf("\n 1 for contitue...and 2 for discontinue..");
		scanf("%d",&ch);
		if(ch==1)
		{
			temp=(struct node*)malloc(sizeof(struct node*));
			printf("Enter next node:");
			scanf("%d",&temp->value);
			ptr->next=temp;
			ptr=temp;//ptr always pointed to last node
			goto choice;
		}
	ptr->next=NULL;
}
void count_node()
{
	int count=0;
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
				count=count+1;
			}
			printf("\n Total number of nodes are %d",count);
	}
}
void search_node()
{
	int data;
	if(first==NULL)
	{
		printf("....\n Link list is empty....");
		return;
	}
	else
	{
		printf("Enter the value to be searched:");
		scanf("%d",&data);
		temp=first;
		while(temp!=NULL)
		{
			if(temp->value==data)
			{
				printf("Searched element %d found..!",data);
				return;
			}
			else
			{
				if(temp->next==NULL)
				{
					printf("Searched element %d not found..!",data);
					return;
				}
				temp=temp->next;
			}
		}
	}
}
void main()
{
	int ch;
	do
	{
		printf("\n1. Create");
		printf("\n2. Count number of nodes");
		printf("\n3. Search specific node in list");
		printf("\n4. Exit");
		printf("\n Enter Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create(); break;
			case 2: count_node(); break;
			case 3: search_node(); break;
			case 4:exit(0);
			default: printf("\nPlease enter any valid choice:");
		}
	}while(1);
}
