#include<stdio.h>
#include<stdlib.h>
int rear=-1,MAXSIZE=10,front=-1,queue[10];
int isfull() {
 if(rear == MAXSIZE - 1)
 return 1;
 else
 return 0;
}
int isempty()
{
	if(front<0 || front>rear)
	return 1;
	else
	return 0;
}
void enqueue()
{  
	if(isfull())
	printf("queue is full \n");
	else
	{    int item;
    printf("enter number to be added \n");
	       	scanf("%d",&item);
	    if(front==-1)
	    front=0;
		rear=rear+1;
		queue[rear]=item;
		printf("%d is added \n",queue[rear]);
	}
}
void dequeue()
{
	if(isempty())
	{
	printf("queue is empty \n");
    }
	else
	{
		int item;
		item=queue[front];
	    front=front+1;
		printf("the element deleted is %d \n",item);
	}
	
}
void display()
{
	if(isempty())
	printf("queue is empty \n");
	else
	{
		int i;
		printf("queue \n");
		for(i=front;i<=rear;i++)
		printf("%d \n",queue[i]);
	}
}
void main()
{
    int choice;
    do
    {
        printf("**** QUEUE OPERATIONS **** \n");
    	printf("1.Add (enqueue) \n");
    	printf("2.delete(dequeue) \n");
    	printf("3.display \n");
    	printf("4.exit \nENTER THE CHOICE\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    enqueue();
	                 break;
            case 2:
                   dequeue();
		           break;
            case 3:
                   display();
		           break;
            case 4: 
                    printf("exiting");
                     exit(0);       
        }
        
    }while(1);
}