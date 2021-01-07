#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL;
void insertbeg()
{
    int num;
    struct node *newnode;
    newnode= malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    newnode->data=num;
    newnode->link=NULL;
    if (start!=NULL)
           newnode->link=start;
    start=newnode;
}
void insertpos()
{
   int num,pos;
   struct node *loc=NULL;
    struct node *newnode;
    newnode= malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    newnode->data=num;
    newnode->link=NULL;
    printf("enter the postion ");
    scanf("%d",&pos);
    loc=start;
    int temp=1;
    while(temp<pos)
     {
      loc=loc->link;
      temp++;
      }
     newnode->link=loc->link;
     loc->link=newnode;
}
void insertend()
{
    struct node *newnode;
    struct node *loc=NULL;
	newnode=malloc(sizeof(struct node));
    int item;
    printf("Enter data:");
    scanf("%d",&item);
	newnode->data=item;
	newnode->link=NULL;
	loc=start;
	while(loc->link!=NULL)
	loc=loc->link;
	loc->link=newnode;
}
void display()
{
	struct node *loc=NULL;
	loc=start;
    printf("linked list:    ");
	while(loc->link!=NULL)
	{
		printf("%d ->",loc->data);
		loc=loc->link;
	}
	printf("%d \n",loc->data);
}
void delete()
{
	struct node *loc=NULL;
    struct node *prev=NULL;
    int item;
    printf("Enter data to be deleted:");
    scanf("%d",&item);
	loc=start;
	if(start->data==item)
	{
		if(start->link!=NULL)
		{
		    start=start->link;
		}
		else
		{
    		start=NULL;
    		printf("\nEmpty list");
    		return;
    	}
	}
	else if
	{
    	while(loc->data!=item)
    	{
    		prev=loc;
    		loc=loc->link;
    	}
     
    		prev->link=loc->link;
    	else
    		{
    		    printf("element not found\n");    
    		   return;
    		}
	}
	display();
}


void main()
{   
    int ch;
    do
    {
       printf("-----menu-----\n 1.Insert a node at the beginning of the list\n2. Insert a node after a particular node in the list");
       printf("\n3. Insert a node at the end of the list\n4. Delete a node containing a particular item\n5.exit");
       printf("\nenter your choice: ");
       scanf("%d",&ch);
       switch (ch)
       {
       case 1:
            insertbeg();
            display();
            break;
       case 2:
            insertpos();
            display();
            break;
       case 3:
            insertend();
            display();
            break; 
       case 4:
             delete();
             break;
       case 5:
           printf("exiting..");
           exit(1);
        }
    } while (1);
     
}