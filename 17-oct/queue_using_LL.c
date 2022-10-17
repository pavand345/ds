#include<stdio.h>
#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *Rear = NULL;
struct node *Front = NULL;

void menu();
void enqueue();
void dequeue();
void print();


int main()
{
	int ch,i;
	while (1)
	{

		menu();         
		printf("Enter your choice of operations : ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: enqueue();
				break;
			case 2:dequeue();
			       break;
			case 3:print();
			       break; 
			case 4:return 0;
			default:printf("Incorrect choice \n");
		}
	}
}
void menu()
{
	printf("1.Enqueue Operation\n");
	printf("2.Dequeue Operation\n");
	printf("3.Display the Queue\n");
	printf("4.Exit\n");

}


void enqueue()
{
	int data,i;
	struct node *newnode;

	newnode=malloc(sizeof(struct node));

	if (newnode == NULL)
	{
		printf("Queue is Fulled.\n");
		return;
	}
	else
	{
		printf("Enter a data : \n");
		scanf("%d",&data);
		newnode->data=data;

		if (Front == NULL)
		{  
			Front=newnode;  
			Rear=newnode;   
			Front->next = NULL;  
			Rear->next = NULL;  
		}  
		else
		{
			Rear->next=newnode;
			Rear=newnode;
			Rear->next=NULL;

		}
	}
}

void dequeue()
{
	struct node *temp;  
	if(Front == NULL)  
	{  
		printf("Queue is Empty. \n");
		return;  
	}  
	else   
	{  
		temp = Front;  
		Front = Front -> next;  
		free(temp);  
	}  
}  

void print()
{  
	struct node *temp=Front;

	while(temp)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
} 
