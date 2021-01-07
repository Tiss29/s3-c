#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *link1;
	int data;
	struct node *link2;
}*start=NULL;
void insert_at_begining(int item)
{
	struct node *newnode=malloc(sizeof(struct node));
	newnode->link1=NULL;
	newnode->link2=NULL;
	newnode->data=item;
	if(start!=NULL)
	{
		start->link1=newnode;
		newnode->link2=start;
		
	}
	
	start=newnode;
}
void insert_after_a_node(int item,int pos)
{
	int temp=0;
	struct node *newnode=malloc(sizeof(struct node));
	struct node *loc,*prev;
	loc=start;
	newnode->data=item;
	while(temp<pos)
	{
		prev=loc;
		loc=loc->link2;
		temp++; 
	}
	prev->link2=newnode;
	newnode->link1=prev;
	loc->link1=newnode;
	newnode->link2=loc;
	
}
void insert_at_end(int item)
{
	struct node *newnode=malloc(sizeof(struct node));
	struct node *loc;
	newnode->data=item;
	newnode->link1=NULL;
	newnode->link2=NULL;
	loc=start;
	while(loc->link2!=NULL)
	loc=loc->link2;
	newnode->link1=loc;
	loc->link2=newnode;
}
void delet(int item)
{
	struct node *loc,*prev;
	loc=start;
	if(start->data==item)
	{
		start=start->link2;
     	start->link1=NULL;
        return;
	}
	while(loc->link2!=NULL&&loc->data!=item)
	{  
		prev=loc;
		loc=loc->link2;
	}
	if(loc->link2!=NULL)
	{
	    loc->link2->link1=loc->link1;
	    prev->link2=loc->link2;
	}
	else if(loc->link2==NULL)
	{
	    prev->link2=NULL;
	}
	else
	printf("element not found\n");
}
void display()
{
	struct node *loc;
	loc=start;
	printf("list: ");
	while(loc->link2!=NULL)
	{
		printf("%d ->",loc->data);
		loc=loc->link2;
	}
	printf("%d \n",loc->data);
}
void main()
{
	int ch,elt,pos;
	printf("1.insert form begining\n2.insert node after a specific position\n3.insert at the end\n4.delete an element\n5.display\n6.exit\n");
	do
	{
		printf("enter choice:   ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter element : ");
				scanf("%d",&elt);
				insert_at_begining(elt);
				break;
			case 2:
				printf("enter element : ");
				scanf("%d",&elt);
				printf("enter position after which the node is to be inserted: ");
				scanf("%d",&pos);
				insert_after_a_node(elt,pos);
				break;
			case 3:
				printf("enter element: ");
				scanf("%d",&elt);
				insert_at_end(elt);
				break;
			case 4:
				printf("enter element to be deleted: ");
				scanf("%d",&elt);
				delet(elt);
				break;
			case 5:
				display();
				break;
			case 6:
				printf("exiting\n");
				break;
			default:
				printf("wrong choice\n");
				break;
		}
		
	}
	while(ch!=6);
}