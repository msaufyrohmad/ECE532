/* 
 * Stack implementation using linked list
 *
 * Computer Engineering UiTM Shah Alam
 *
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top;

void push(int n);
void read();
int pop();
int isEmpty();

void push(int n)
{
	printf("-> %d pushed! \n",n);
	if(top==0)
	{
		top=(struct node*)malloc(sizeof(struct node));
		top->data=n;
		top->next=NULL;
	}
	else
	{
		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=n;
		temp->next=top;
		top=temp;
	}
}

int pop()
{
	struct node *temp=top;
	top=top->next;
	return temp->data;
}

void read()
{
	struct node *temp=top;
	printf("Stack Contains: \n");
	while(temp)
	{
		printf("%d \n",temp->data);
		temp=temp->next;
	}
}

int isEmpty()
{
	if(top==0)
		return 1;
	else
		return 0;
}

int main()
{
	push(10);
	push(20);
	push(30);
	read();
	if(!isEmpty())
	printf("-> %d popped! \n",pop());
	read();
	push(40);
	read();
}
