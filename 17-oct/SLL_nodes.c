//Create a list with 3 nodes having int data in single Linked list data : 100,200,300


#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node{
	int data;
	struct node *next;
}*head;

void create_node(void);
void print(void);

void my_menu()
{
	printf("\n... CHOICE...\n");
	printf("c : create a node\n");
	printf("p : print the list\n");
	printf("q : quit\n");
}

int main()
{
	char ch;
	while(1)
	{
		my_menu();

		printf("\nEnter a choice : ");
		__fpurge(stdin);
		scanf("%c",&ch);

		switch(ch)
		{
			case 'c' : create_node();
				   break;
			case 'p' : print();
				   break;
			case 'q' :return 0;
		}
	}
}

void create_node(void)
{
	struct node *newnode,*temp;
	int i,data,n;
	head=NULL;
	printf("Enter a no. nodes : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=malloc(sizeof(struct node));

			printf("Enter a data : ");
			scanf("%d",&data);

			head->data=data;
			head->next=NULL;
			temp=head;
		}
		else
		{
			newnode=malloc(sizeof(struct node));

			printf("Enter a data : ");
			scanf("%d",&data);

			newnode->data=data;
			newnode->next=NULL;

			temp->next=newnode;
			temp=temp->next;
		}
	}
}

void print(void)
{
	while(head)
	{
		printf("data is : %d\n",head->data);
		head=head->next;
	}
}


