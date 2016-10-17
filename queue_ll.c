#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*front;

void enqueue(int n)
{
	printf("-> %d enqueued! \n",n);
	if(front==0)
	{
		front=(struct node*)malloc(sizeof(struct node));
		front->data=n;
		front->next=NULL;
	}
	else
	{
		struct node *nw=(struct node*)malloc(sizeof(struct node));
		nw->data=n;
		struct node *temp=front;
		while(temp->next!=NULL)
		{
			temp=temp->next;		
		}
		temp->next=nw;
	}
}

void read()
{
	struct node *temp=front;
	printf("Read Queue Content: \n");
	while(temp)
	{
		printf("%d \n",temp->data);
		temp=temp->next;
	}
}

int dequeue()
{
	struct node *temp=front;
	front=front->next;
	printf("-> %d dequeued!\n",temp->data);
	return temp->data;	
}

int isEmpty()
{
	if(front==0)return 1;
	else return 0;
}

int main()
{
	enqueue(10);	
	if(!isEmpty())enqueue(20);	
	if(!isEmpty())enqueue(30);	
	if(!isEmpty())enqueue(40);	
	if(!isEmpty())enqueue(50);	
	read();	
	dequeue();
	read();	
} 
