#include<iostream>
#include <cstring>
using namespace std;
#define MAX 10
class MinStack
{
	public:
	int upper;
	int a[MAX];
	MinStack()
	{
		upper = -1;
	}
bool isempty()
{
	return (upper < 0);
}
void push(int val)
{
	if(upper > MAX - 1){
		cout << "Satck overflow"<< endl;
	}
	else
		a[++upper] = val;
}
void pop()
{	
	int x;
	if(isempty())
	{
		cout << "Stack is empty"<< endl;
	}
	else
		 x = a[upper--];
}
int top()
{
if(isempty())
{
	cout << "Stack is empty"<< endl;
	return 0;
}
else
{
	cout << a[upper] <<endl;
   return a[upper];
}
}
int getMin()
{
	int x = a[0];
	for(int i = 0;i < upper;i++)
	{
		if(a[i+1]<x)
		{
			x = a[i+1];
		}
	}
	cout << x <<endl;
	return x;
}
};
int main(int argc, char *argv[])
{
	MinStack minstack;
	minstack.push(-2);
	minstack.push(0);
	minstack.push(-3);
	minstack.getMin();
	minstack.pop();
	minstack.top();
	minstack.getMin();
}
