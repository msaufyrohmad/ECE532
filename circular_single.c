/* 
 * Single circular linked list in c
 * ECE532 Data Structure and Algorithms
 * Computer Engineering UiTM Shah Alam
 * Muhammad Saufy Rohmad
 * saufy@salam.uitm.edu.my
 *
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head;

void add(int n);
void read();
void del();

int main()
{
	add(10);
	add(20);
	add(30);
	add(40);
	add(50);
	read();
	del();
	del();
	read();
}

void add(int n)
{
if(head==0)
{
	head=(struct node*)malloc(sizeof(struct node));
	head->data=n;
	head->next=head;
}
else
{
	struct node *nw;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=n;
	nw->next=head;
	struct node* temp=head;
	if(temp->next==head)
	{
		temp->next=nw;
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=nw;
	}	
}
}
void read()
{
	struct node* temp=head;
	if(temp->next==head)
		printf("%d in %u next: %u \n",temp->data,temp,temp->next);
	else
	{
	
		while(temp->next!=head )
		{
			printf("%d in %u \n",temp->data,temp);
			temp=temp->next;
		}		
			printf("%d in %u \n",temp->data,temp);
	}
}

void del()
{
	struct node *temp=head;
	while(temp->next->next!=head)
	{
		temp=temp->next;
	}
	struct node *de = temp->next;
	temp->next=head;
	free(de);
}
		



