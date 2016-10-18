#include<stdio.h>

int main()
{
	int **p;
	int *k;
	int x=10;
	k=&x;
	p=&k;
	printf("%d ",**p);
}
