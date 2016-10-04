/* 
 * Simple single linked list oprations program
 * ECE532 Data Structure and Algorithms
 * FKE UiTM
 * wrote by:
 * Muhammad Saufy Rohmad msaufy@yahoo.co.uk
 *
 * functions:
 * 	add_end(int) - add node to the end of linked list
 * 	read() - read all nodes
 * 	delete_end() - delete end nodes (tail node)
 */
#include<stdio.h>
#include<stdlib.h>
void add_end(int);
void read();
void delete_end();

struct node 
{
	int data;
	struct node *next;
}*head;

void add_end(int n)
{
if(head==0)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data=n;
	new->next=NULL;
	head=new;
}
else
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data=n;
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=NULL;
}

}
	
void read()
{
	struct node *temp=head;
	while(temp)
	{
		printf("node at %u, store %d, next is %u\n",temp,temp->data,temp->next);
		temp=temp->next;
	}
}

void delete_end()
{
	struct node *temp=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	printf("node at %u with data %d deleted! \n",temp->next,temp->next->data);
	temp->next=NULL;
}

int main()
{
	add_end(10);
	add_end(20);
	add_end(30);
	add_end(40);
	add_end(50);
	read();
	delete_end();
	read();

}
