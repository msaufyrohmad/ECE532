/* 
 * Double linked list
 * Muhammad Saufy Rohmad
 * Computer Engineering UiTM
 * saufy@salam.uitm.edu.my
 */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*head;

void add(int n);
void del();
void read();
void del();

int main()
{
	add(10);
	add(20);
	add(30);
	read();
	del();
	read();
	
}

void add(int n)
{
if(head==0)
{	
	head=(struct node*)malloc(sizeof(struct node));
	head->data=n;
	head->next=NULL;
	head->prev=NULL;
}
else
{
	struct node *nw;
	nw=(struct node*)malloc(sizeof(struct node));
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=nw;
	nw->data=n;
	nw->next=NULL;
	nw->prev=temp;
}

}

void read()
{
	int count=0;
	struct node *temp=head;
	while(temp)
	{
		count++;
		printf("%d in loc: %u \n",temp->data,temp); 
		temp=temp->next;
	}
	printf("Total %d nodes \n",count); 
}

void del()
{
	struct node *temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	struct node *de=temp->next;
	temp->next=NULL;
	free(de);
}


