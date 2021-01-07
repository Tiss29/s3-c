#include<stdio.h>
#include<stdlib.h>
#define size 5
int rear=-1,front=-1,CQ[size];
int isempty()
{
	if(front==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if((front==rear+1) || (front==0 && rear==size-1))
	return 1;
	else 
	return 0;
}
void insert()
{   int elt;
	if(isfull())
	printf("overflow\n");
	else
	{   printf("enter an element\n");
		 scanf("%d",&elt);
		if(front==-1)
		front=0;
		rear=(rear+1)%size;
		CQ[rear]=elt;
		printf("%d is inserted",elt);
	}
}
void delete()
{
	int elem;
	if(isempty())
	{
		printf("underflow \n");
	}
	else
	{
		elem=CQ[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		front=(front+1)%size;
		printf("the element deleted is: %d \n",elem);
	}
}
void display()
{ int i;
	if(isempty())
	printf("underflow");
	else
	{
		printf("the circular queue is:\n");
		for(i=front;i<=rear;i++)
		printf("%d \n",CQ[i]);
	}
}
void main()
{
	int ch,element;
	do
	{
	printf("***CIRCULAR QUEUE***\n");
	printf("1.insert\n2.delete\n3.display\n4.exit");
	printf("Enter your choice : "); 
    scanf("%d",&ch);
	switch(ch)
	{
	    case 1:{ 
		        insert();
		        break;
	           }
		case 2: delete();
	            break;
        case 3: display();
                break;
        case 4: printf("exiting");
                exit(0);
                break;
       
    }
	
    }
   while(1);
}