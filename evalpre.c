#include<stdio.h>
#include<stdlib.h>      
#include<ctype.h>     
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int isoper(char sym)
{
	if(sym == '^' || sym == '*' || sym == '/' || sym == '+' || sym =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}


void Eval(char prefix[],int k)
{

    int i;
    char ch;
    int val;
    int A, B;
      for (i = k; i>=0; i--) {
        ch = prefix[i];
        if (isdigit(ch)) {
            
            push(ch-'0');
        }
        else if (isoper(ch)==1) {
            
            A = pop();
            B = pop();

            switch (ch) 
            {
            case '*':
                val = A * B;
                break;

            case '/':
                val = A / B;
                break;

            case '+':
                val = A + B;
                break;

            case '-':
                val = A - B;
                break;
            }

            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}
int main()
{   int i;
	char  prefix[SIZE];       
	printf("\nEnter prefix expression (pl.put '.'@the end)  : \n");
    for (i = 0; i <= SIZE - 1; i++) {
        scanf("%c", &prefix[i]);

        if (prefix[i] == '.') 
        {
            break;
        } 
    }
    char alp;
    for(int j=0;j<=i;j++)
    {   alp=prefix[j];
        if(isalpha(alp))
        {
            printf("enter the value of %c \t",alp);
            scanf(" %c",&prefix[j]);
        }
    }
    
    Eval(prefix,i);

    return 0;
}