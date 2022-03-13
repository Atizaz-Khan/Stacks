	#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
	public:
	int size;
	int top;
	char *arr;
};
int isempty(Stack* ptr)
{
	if(ptr->top == -1)
		return 1;
	else
		return 0;
}
int isfull(Stack *ptr)
{
	if(ptr->top == ptr->size-1)
		return 1;
	else 
		return 0;
}
void push(Stack* ptr,int val)
{
	if(isfull(ptr))
		cout << "Stack Overflow" <<endl;
	else
		ptr->top++;
		ptr->arr[ptr->top] = val;
}
int pop(Stack* ptr)
{
	int val;
	if(isempty(ptr))
		cout << "Stack underflow"<<endl;
	else
		 val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
}
int top(Stack* ptr)
{
	if (isempty(ptr))
	{
		cout << "Stack is empty" << endl;
		return 0;
	}
	else {
		int val = ptr->arr[ptr->top];
		return val;
	}
}
int isoperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;
	else
		return 0;
}
int precedence(char ch)
{
	if(ch == '^')
		return 3;
	if(ch == '*' || ch == '/')
		return 2;
	if(ch == '+' || ch == '-')
		return 1;
	else 
		return -1;
}
char* infixtopostfix(char* infix)
{
	Stack *sp = new Stack();
	sp->top = -1;
	sp->size = 100;
	sp->arr = new char[sp->size];
	char *postfix = new char[(strlen(infix) + 1)];
	int i = 0;
	int j = 0;
	while(infix[i] != '\0')
	{
		if(infix[i] == '('|| infix[i]==')')
		{
			push(sp,infix[i]);
			pop(sp);
			i++;
		}
		else{
		
		if(!isoperator(infix[i]))
		{
			postfix[j] = infix[i];
			i++;
			j++;
		}
		else
			if(precedence(infix[i]) > precedence(top(sp)))
			{
				push(sp,infix[i]);
				i++;
			}
			else
			{
				postfix[j] = pop(sp);
				j++;
			}
		}
	}
		while(!isempty(sp))
		{
				postfix[j] = pop(sp);
				j++;
		}
		postfix[j] = '\0';
		return postfix;
}
int main()
{
	char* infix =  "a+b*(c^d-e)^(f+g*h)-i";
	cout << infixtopostfix(infix) << endl;
	return 0;
}
