#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*head;

void read();
void add(int n);
void delete();

int main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add(50);
	read();
	delete();
	read();
}

void add(int n)
{
if(head==0)
{
	head=(struct node*)malloc(sizeof(struct node));
	head->data=n;
	head->next=head;
	head->prev=head;
}
else
{	if(head->next==head)
	{
		struct node *nw;
		nw=(struct node*)malloc(sizeof(struct node));
		nw->data=n;
		nw->next=head;
		nw->prev=head;
		head->prev=nw;
		head->next=nw;
	}
	else
	{
		struct node *nw;
		nw=(struct node*)malloc(sizeof(struct node));
		nw->data=n;
		head->prev=nw;
		nw->next=head;
		struct node *temp=head;
		while(temp->next!=head)
			temp=temp->next;
		temp->next=nw;
	}
}
}

void read()
{
	int c=0;
	struct node *temp=head;
	while(temp->next!=head)
	{
		c++;
		printf("%d in %u \n",temp,temp->data);
		temp=temp->next;
	}
	c++;
	printf("%d in %u \n",temp,temp->data);
	printf("number of nodes : %d\n",c);
}

void delete()
{
	struct node *temp=head;
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	struct node *del=temp->next;
	temp->next=head;
	head->prev=temp;


}

	
