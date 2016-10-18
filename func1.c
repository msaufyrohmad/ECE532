#include<stdio.h>

void f1(int);
void f2(int);
void f3(int);

int main()
{
	f1(5);
	printf("MAIN \n");
}

void f1(int n)
{
	f2(6);
	printf("F1 %d \n",n++);
}

void f2(int n)
{
	f3(7);
	printf("F2 %d \n",n++);
}

void f3(int n)
{
	printf("F3 %d \n",n++);
}
