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

int precedence(char sym)
{
	if(sym == '^')
	{
		return(3);
	}
	else if(sym == '*' || sym == '/')
	{
		return(2);
	}
	else if(sym == '+' || sym == '-')          
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InToPost(char infix[], char postfix[])
{ 
	int i=0, j=0;
	char x;
	push('(');                               
	strcat(infix,")");                  
	char item=infix[i];         
	while(item != '\0')        
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix[j] = item;              
			j++;
		}
		else if(isoper(item) == 1)     
		{
			x=pop();
			while(isoper(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix[j] = x; 
				j++;
				x = pop();      
			}
			push(x);
			push(item);                 
		}
		else if(item == ')')         
		{
			x = pop();               
			while(x != '(')              
			{
				postfix[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ 	printf("\nInvalid infix Expression.\n");       
			exit(1);
		}
		i++;


		item = infix[i]; 
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");       
		exit(1);
	}
	postfix[j] = '\0';

}
int main()
{
	char infix[SIZE], postfix[SIZE];       
	printf("\nEnter Infix expression : ");
	gets(infix);

	InToPost(infix,postfix);                   
	printf("Postfix Expression: ");
	puts(postfix);                     

	return 0;
}
