/*
 * Stack implementation using array
 *
 * Computer Engineering UiTM Shah Alam
 */

#include<stdio.h>
#define SIZE 10
int st[SIZE];
int top=-1;

void push(int n)
{
	top++;
	st[top]=n;
}

int pop()
{
	int x=st[top];
	top--;
}


int isFull()
{
	if(top==SIZE-1)
		return 1;
	else	
		return 0;
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void read()
{
 int n;
printf("inside stack is:\n");
for(n=0;n<=top;n++)
	printf("%d ",st[n]);

}

int main()
{
	push(10);
	push(20);
	push(30);
	read();
}
