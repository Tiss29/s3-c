#include<stdio.h>
#include <stdlib.h>
#define max 10
int stack[10],top1=-1,top2=max-1;
void push (int item,int ch )
{    
   
    if (top1>=top2)
       printf("stack full");
    else
    { 
      if(ch==1)
        {
           
           ++top1;
           stack [top1] = item;
           printf("%d is added to the stack",item);
        }
        else if(ch==2)
        {
           top2--;
           stack [top2] = item;
           printf("%d is added to the stack",item);
        }
        else
        printf("your choice is wrong");
    }
}
int isempty()
{
  if ((top1 == -1)&&(top2==max-1))
    return 1;
  else
   return 0;
}
void pop(int ch)
{ int data;
  if(!isempty()) 
  {  
  
      if(ch==1)
     {
         data = stack[top1];
         top1 = top1 - 1;
         printf("%d is popped out",data);
     }
     else if(ch==2)
     {  data = stack[top2];
         top2 = top2 + 1;
         printf("%d is popped out",data);
     }
     else
     printf("wrongchoice");
  }
  else
     printf("Could not retrieve data, Stack is empty.\n");
}
int peek(int ch)
{ 
    
  if(ch==1)
    {printf("%d ",stack[top1]);
 return stack[top1];
    }
    else
    {printf("%d ",stack[top2]);
 return stack[top2];
    }
        
    
}
void display(int ch)
{ if(ch==1)
 {for(int i=0;i<=top1;i++)
  printf("%d  ",stack[i]);
 }
 else
 {for(int i=top2;i<=size-1;i++)
  printf("%d  ",stack[i]);
 }
}
void main()
{    int ch;
     int item;
    int choice;
    do
    {  
        printf("\n*OPTIONS*\n1.Push \t  2.Pop \t ");
        printf("3.Peek \t 4.Display\t 5.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{ printf("where u have to enter the item \t1.stack1\t  2.stack2\n");
                     scanf("%d",&ch);
                     printf("enter the item to input to the stack: ");
                     scanf("%d",&item);
                     push(item,ch);
                     break;
                   }
            case 2:{
                     printf("from which stack you need to delete\t1.stack1\t2.stack2\n");
                     scanf("%d",&ch);
                     pop(ch);
                     break;
                   }
            case 3:{
                    printf("from which stack you need to peek\t1.stack1\t2.stack2\n");
                    scanf("%d",&ch);
                    peek(ch);
                    break;
                   }
            case 4:{
                       printf("from which stack you need to display\t1.stack1\t2.stack2\n");
                       scanf("%d",&ch);
                       display(ch);
                       break;
                    }
            case 5: printf("exit....");
                   exit(0);       
        }
        
    }while(1);
}