#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head;

void create_node(int n);
void display();
int swap(int pos1,int pos2);
int count_list();


int main()
{
	int n,pos1,pos2;

	printf("Enter the number of nodes to be added : ");
	scanf("%d",&n);

	create_node(n);

	printf("Linked list data before swaping : \n");
	display();

	printf("Enter the 1st position : ");
	scanf("%d",&pos1);
	printf("Enter the 2nd position : ");
	scanf("%d",&pos2);

	if(swap(pos1,pos2)==1)
	{
		printf("Linked list data after swaping :\n ");
		display();
	}
	else
	{
		printf("Invalid position give the correct Position.\n");
	}

	return 0;
}



void create_node(int n)
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


void display()
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


int count_list()
{
	struct node *temp;
	int node=0;
	while(temp!=NULL)
	{
		node++;
		temp=temp->next;
	}
	return node;
}


int swap(int pos1,int pos2)
{
	struct node *node1, *node2, *prev1, *prev2, *temp;
	int i;
	const int maxpos=(pos1>pos2)?pos1:pos2;
	const int cnt=count_list();

	i=1;
	temp=head;
	prev1=NULL;
	prev2=NULL;

	while(temp!=NULL && (i<=maxpos))
	{
		if(i==pos1-1)
			prev1=temp;
		if(i==pos1)
			node1=temp;

		if(i==pos2-1)
			prev2=temp;
		if(i==pos2)
			node2=temp;
		temp=temp->next;
		i++;
	}

	if(node1 != NULL && node2 != NULL)
	{
		if(prev1 != NULL)
			prev1->next=node2;
		if(prev2 != NULL)
			prev2->next=node1;

		temp=node1->next;
		node1->next=node2->next;
		node2->next=temp;

		if(prev1==NULL)
			head=node2;
		else if(prev2==NULL)
			head=node1;

		return 1;
	}
	if((pos1 <= 0|| pos1 > cnt)||(pos2 <= 0 || pos2 > cnt))
	{
		return -1;
	}
	if(pos1==pos2)
		return 1;


}
