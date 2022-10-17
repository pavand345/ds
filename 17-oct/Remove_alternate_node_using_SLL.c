#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node{
	int data;
	struct node *next;
}*head;


void input(int n);
void delete(void);
void display(void);

int main()
{
	int n;
	char choice;

	printf("Enter the number of nodes : ");
	scanf("%d",&n);

	while(1)
	{

		printf("i : input \n");
		printf("r : remove\n");
		printf("d : display\n");
		printf("x : Exit\n");
		__fpurge(stdin);
		printf("Enter the choice : ");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'i' : input(n);
				   break;
			case 'r' : delete();
				   break;
			case 'd' : display();
				   break;
			case 'x': return 0;
			default :printf("Invalid choice.");
		}
	}
	return 0;
}

void input(int n)
{
	struct node *newNode, *temp;
	int data, i;

	head=(struct node *)malloc(sizeof(struct node ));

	if(head == NULL)
	{
		printf("Memory cannot be allocated. ");
		return ;
	}
	printf("Enter the data : ");
	scanf("%d",&data);

	head->data=data;
	head->next=NULL;

	temp=head;

	for(i=2;i<=n;i++)
	{
		newNode=(struct node *)malloc(sizeof(struct node));

		if(newNode==NULL)
		{
			printf("Memory cannot be allocate");
			break;
		}

		printf("Enter the data : ");
		scanf("%d",&data);

		newNode->data=data;
		newNode->next=NULL;

		temp->next=newNode;
		temp=temp->next;
	}
}


void delete(void)
{
	struct node *prev,*newnode=NULL;
	if(head==NULL)
	{
		printf("No data present.");
		return ;
	}
	prev=head;
	newnode=head->next;
	while(prev != NULL && newnode != NULL)
	{
		prev->next=newnode->next;
		free(newnode);
		prev=prev->next;
		if(prev!=NULL)
			newnode=prev->next;
	}
}


void display(void)
{
	struct node *temp;

	if(head ==NULL)
	{
		printf("No memory present .\n") ;
		return;

	}
	temp = head;

	while(temp!=NULL)
	{
		printf("Data is = %d\n",temp->data);
		temp=temp->next;
	}
}
