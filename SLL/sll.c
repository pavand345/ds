#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
}s;
s *head=NULL;



/*inserting the  nodes*/
s *insert()
{
	s *temp=NULL,*new=NULL;
	int n,i;
	printf("Enter the no.of nodes u want : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=(s*)malloc(sizeof(s));
			printf("Enter the data : ");
			scanf("%d",&(head->data));
			head->link=NULL;
			temp=head;
		}
		else
		{
			new=(s*)malloc(sizeof(s));
			printf("Enter the data : ");
			scanf("%d",&(new->data));
			new->link=NULL;
			temp->link=new;
			temp=temp->link;
		}
	}
}



/*Displaying the linked list*/
s *display()
{
	s *temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(temp)
		{
			printf("\033[1;36m%d \033[0m",temp->data);
			temp=temp->link;
		}
	}
}


/*reversing the linked list*/
s *reverse()
{
	s *prev=NULL,*curr=NULL,*next=NULL;
	next=head;
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		while(next)
		{
			prev=curr;
			curr=next;
			next=next->link;
			curr->link=prev;
		}
		head=curr;
		printf("list reversed successfully\n");
	}
}


/*inserting a node at begining*/
s *at_beg()
{
	s *temp,*new;
	temp=head;
	new=(s*)malloc(sizeof(s));
	printf("enter the data : ");
	scanf("%d",&(new->data));
	new->link=temp;
	head=new;
	printf("Inserted at begining successfully\n");
}


/*inserting at ending*/
s *at_end()
{
	s *temp=head,*new;
	new=(s*)malloc(sizeof(s));
	printf("Enter the data : ");
	scanf("%d",&(new->data));
	new->link=NULL;
	while(temp->link)
	{
		temp=temp->link;
	}
	temp->link=new;
	printf("Inserted at end successfully\n");
}


/*inserting a node at given postion*/
s *at_pos()
{
	s *temp=head,*new;
	int i,n;
	printf("enter the position to insert node : ");
	scanf("%d",&n);

	new=(s*)malloc(sizeof(s));
	printf("Enter the data : ");
	scanf("%d",&(new->data));
	new->link=NULL;

	if(n==1)
	{
		new->link=temp;
		head=new;
	}
	else
	{
		for(i=1;i!=(n-1);i++)
		{
			temp=temp->link;
		}
		new->link=temp->link;
		temp->link=new;
	}
	printf("Inserted at given position successfully\n");
}


/*Deleted a node at beginging*/
s *dlt_beg()
{
	s *temp=head;
	if(head==NULL)
		printf("No nodes are available\n");
	else
	{
		head=temp->link;
		free(temp);
		printf("Deleted a node at begining successfully\n");
	}
}


/*Deleted  a node at ending*/
s *dlt_end()
{
	s *temp=head;
	if(head==NULL)
		printf("no nodes are available\n");
	else if(head->link==NULL)
		printf("only single node is available\n");
	else
	{
		while(temp->link->link!=NULL)
		{
			temp=temp->link;
		}
		free(temp->link);
		temp->link=NULL;
		printf("Deleted a node at end successfully\n");
	}
}


/*Deleted a node at gvn position*/
s *dlt_pos()
{
	s *prev=head;
	s *temp=head;
	int i,n;
	printf("enter the position u want delete : ");
	scanf("%d",&n);
	if(i==1)
		dlt_beg();
	else
	{
		for(i=1;i!=n-1;i++)
		{
			prev=temp;
			temp=temp->link;
		}
		prev->link=temp->link;
		free(temp);
	}
	printf("Deleted a node at gvn postion successfully\n");
}



/*main function*/
void main()
{
	int ch;
	while(1)
	{
		printf("\n1.insert\t2.display\t3.reverse\t4.Add at begining\t5.Add at end\t6.Add at given position\n7.delete at begin\n8.delete at end\n9.delete at position\n/********Enter the choice*********/ : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			       break;
			case 2:display();
			       break;
			case 3:reverse();
			       break;
			case 4:at_beg();
			       break;
			case 5:at_end();
			       break;
			case 6:at_pos();
			       break;
			case 7:dlt_beg();
			       break;
			case 8:dlt_end();
			       break;
			case 9:dlt_pos();
			       break;
			default : printf("Entered wrong choice\n");
				  exit(0);

		}
	}
}
