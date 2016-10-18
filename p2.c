#include<stdio.h>

int *sum(int *x,int *y)
{
	int z;
	z=*x+*y;
	return &z;
}	

int main()
{
	int x=10,y=20;
	int *z=sum(&x,&y);
	printf("%d \n",*z);
}

