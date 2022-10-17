#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node{
        char data;
        struct node *next;
}*head=NULL;

void create_node(int n);
void print(int n);

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
        int n;
        printf("Enter a no. nodes : ");
        scanf("%d",&n);
        while(1)
        {
                my_menu();

                printf("\nEnter a choice : ");
                __fpurge(stdin);
                scanf("%c",&ch);

                switch(ch)
                {
                        case 'c' :if(n==0)
                                  {
                                          printf("Memory not initialized.\n");
                                          return 0;
                                  }
                                  create_node(n);
                                  break;
                        case 'p' : print(n);
                                   break;
                        case 'q' :return 0;
                }
        }
}

void create_node(int n)
{
        struct node *newnode,*temp;
        int i;
        char data;

        if(n==0)
        {
                printf("Memory not initialized.\n");
                return ;
	 }
        for(i=0;i<n;i++)
        {
                if(head==NULL)
                {
                        head=malloc(sizeof(struct node));

                        printf("Enter a data : ");
                        __fpurge(stdin);
                        scanf("%c",&data);

                        head->data=data;
                        head->next=head;
                        temp=head;
                }
                else
                {
                        newnode=malloc(sizeof(struct node));

                        printf("Enter a data : ");
                        __fpurge(stdin);
                        scanf("%c",&data);

                        newnode->data=data;
                        newnode->next=head;

                        temp->next=newnode;
                        temp=temp->next;

                }
        }
}

void print(int n)
{
        while(n)
        {
                printf("data is : %c\n",head->data);
                head=head->next;
                n--;
        }
}

