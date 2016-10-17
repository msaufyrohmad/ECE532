/* 
 * Linear Queue implementation using array
 *
 * Computer Engineering UiTM Shah Alam
 * Muhammad Saufy Rohmad
 *
 */

#include<stdio.h>
#define SIZE 10

int q[SIZE];
int front=-1;
int rear=-1;

void enqueue(int n);
int dequeue();
int isFull();
int isEmpty();
void read();

void enqueue(int n)
{
	printf("-> %d queued!\n",n);
	if(front==-1)
		front++;
	rear++;
	q[rear]=n;
}

int dequeue()
{
	int temp;
	temp=q[front];
	front++;
	printf("-> %d dequeued!\n",temp);
	return temp;
}

int isFull()
{
	if(rear==SIZE-1)
		return 1;
	else
		return 0;	
}

int isEmpty()
{
	if(rear==-1)
		return 1;
	else
		return 0;
}

void read()
{
	int x;
	printf("Content of linear queue: \n");
	for(x=front;x<=rear;x++)
		printf("%d \n",q[x]);
}
int main()
{
	if(!isFull())enqueue(10);
	if(!isFull())enqueue(20);
	if(!isFull())enqueue(30);
	if(!isFull())enqueue(40);
	if(!isFull())enqueue(50);
	read();
	if(!isEmpty())dequeue();
	read();
}


