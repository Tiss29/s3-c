#include<stdio.h>
#define size 4
int CQ[size],front=-1,rear=-1;
int CQempty()
{
	if(front==-1 && rear==-1)
	return 1;
	else
	return 0;
}
int CQfull()
{
	if((front==rear+1) || (front==0 && rear==size-1))
	return 1;
	else 
	return 0;
}
void insert_rear(int elt)
{
	if(CQfull())
	printf("overflow\n");
	else
	{
		if(front==-1)
		front=0;
		rear=(rear+1)%size;
		CQ[rear]=elt;
		printf("element entered\n");
	}

}
void delete_front()
{
	int elem;
	if(CQempty())
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
		printf("the element deleted from front is:  %d\n",elem);
	}
}
void insert_front(int elt)
{
	if(CQfull())
	printf("overflow\n");
	else
	{
		if(front==-1&& rear==-1)
		{
			front=0;
			rear=0;
			CQ[front]=elt;
		}
		else if(front==0)
		{
			front=size-1;
			CQ[front]=elt;
		}
		else
		{
			--front;
			CQ[front]=elt;
		}
		printf("element entered\n");
	}
}
void delete_rear()
{
	int item;
	if(CQempty())
	printf("underflow\n");
	else
	{
		if(front==rear)
		{
			item=CQ[rear];
			rear=-1;
			front=-1;
		}
		else if(rear==0)
		{
			item=CQ[rear];
			rear=size-1;
		}
		else
		{
			item=CQ[rear];
			rear--;
		}
		printf("the element deleted from rear is:   %d\n",item);
	}
	
}
void display()
{
	int i;
	if(CQempty())
	printf("underflow\n");
	else
	{   printf("queue:");
		for(i=front;i<=rear;i++)
		{
			printf("%d  ",CQ[i]);
		}
		printf("\n");
	}
}
void main()
{
	int ch,elem;
	printf("***DEQUE OPERATIONS***\n");
	printf("1.insert from front\n2.insert from rear\n3.delete from front\n4.delete from rear\n 5.display \n");
	do
	{
		printf("enter choice:  ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	    	case 1:printf("enter element to be insertedfrom front:  ");
	    	       scanf("%d",&elem);
	    	       insert_front(elem);
	    	       break;
	    	case 2:printf("enter element to be inserted from rear:  ");
	    	       scanf("%d",&elem);
	    	       insert_rear(elem);
	    	       break;
	    	case 3:delete_front();
	    	       break;
			case 4:delete_rear();
			       break;
			case 5:display();
			       break;
                        case 6:printf("exiting..");
                               break;

			default:printf("wrong choice\n");   
			        
	    }
	}
	while(ch!=6);
	
}