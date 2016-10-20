/*
 *Circular Queue Implementation on Array
 *
 * Partially handwritten and partially copied from pumtambekar Data Structure and Algorithm
 * Almost done on myself but little 'glinch' on read function hehe
 *
 * Computer Engineering UiTM Shah Alam
 * Muhammad SAufy Rohmad
 */

#include<stdio.h>
#define SIZE 8

int q[SIZE];
int front=-1;
int rear=-1;

void push(int n)
{
	if(front==-1)
		front=(front+1)%SIZE;
	rear=(rear+1)%SIZE;
	q[rear]=n;
	printf("Front n Rear : %d %d\n",front,rear);
}

int pop()
{
	int x= q[front];
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%SIZE;
	printf("Front n Rear : %d %d\n",front,rear);
	return x;
}	

void read()
{
	int x;
	printf("Circular Queue : ");
	for(x=front;x!=rear;x=(x+1)%SIZE)
		printf("%d ",q[x]);
		printf("%d ",q[x]);
}
int ifEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

int ifFull()
{
	if(front=(rear+1)%SIZE)
		return 1;
	else
		return 0;
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	pop();
	read();
}



