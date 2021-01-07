#include<stdio.h>
#include <stdlib.h>
int stack[10],top=-1,MAX=10;
void push ( )
{    
   
    if (top == (MAX-1))
       printf("stack full");
    else
    { printf("enter the item to input to the stack\n");
    int item;
    scanf("%d",&item);
      ++top;
      stack [top] = item;
      printf("%d is added to the stack",item);
    }
}
int isempty()
{
  if (top == -1)
    return 1;
  else
   return 0;
}
void pop()
{ int data;
  if(!isempty()) 
  {
     data = stack[top];
     top = top - 1;
     printf("%d is popped out",data);
  }
  else
     printf("Could not retrieve data, Stack is empty.\n");
}
int peek()
{ printf("%d ",stack[top]);
 return stack[top];
}
void display()
{
 for(int i=0;i<=top;i++)
  printf("%d  ",stack[top]);
}
void main()
{
    int choice;
    do
    {
        printf("\n*OPTIONS*\n1.Push an item into the stack\n2.Pop an item from the stack\n");
        printf("3.Peek the top item of the stack\n4.Display\n5.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    push();
                    break;
            case 2:
                  pop();
                   break;
            case 3:
                   peek();
                   break;
            case 4:
                   display();
                    break;
            case 5: printf("exit....");
                   exit(0);       
        }
        
    }while(1);
}