/*7. Implement stack using link list.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
}*top,*ptr;

void push()
{
	ptr=(struct node*)malloc(sizeof(struct node*));
	if(ptr==NULL)
	{
		printf("\n STACK OVERFLOW..!!");
		return;
	}
	else
	{
		if(top==NULL)
		{
			printf("\nENTER 1st Node:");
			scanf("%d",&ptr->value);
			ptr->next=NULL;
			top=ptr;
		}
		else
		{
			printf("\nENTER Node:");
			scanf("%d",&ptr->value);
			ptr->next=top;
			top=ptr;
		}
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("\n STACK UNDERFLOW..!!!");
		return;
	}
	else
	{
		ptr=top;
		top=ptr->next;
		printf("\n DELETED VALUE IS %d",ptr->value);
		free(ptr);
	}
}
void peep()
{
	if(top==NULL)
	{
		printf("\n STACK is empty..!!!");
		return;
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->value);
			ptr=ptr->next;
		}
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("\n1. Push \n2. Pop \n3. peep \n4. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			          break;
			case 2:pop();
			          break;
			case 3:peep();
			          break;
			case 4:exit(0);
			default: printf("\n Please enter valid choice 1-4:");
		}
	}
}

