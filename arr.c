#include<stdio.h>
#define SIZE 10
int sum(int x[],int size);
int average(int total,int size);
int large(int x[],int size);
int small(int x[],int size);

int main()
{
	int x[10]={1,2,3,4,5,6,7,8,9,10};
	int total=sum(x,SIZE);
	printf("sum :%d \n",total);
	printf("average :%d \n",average(total,SIZE));
	printf("largest :%d \n",large(x,SIZE));
	printf("smallest :%d \n",small(x,SIZE));
}

int sum(int x[],int size)
{
	int c,sum=0;
	for(c=0;c<size;c++)
		sum=sum+x[c];
	return sum;
}
	 
int average(int total,int size)
{
	return total/size;
}

int large(int x[],int size)
{
	int c,l=x[0];
	for(c=0;c<size;c++)
	{
		if(x[c]>l)
		l=x[c];
	}
	return l;
}

int small(int x[],int size)
{
	int c,s=x[0];
	for(c=0;c<size;c++)
	{
		if(x[c]<s)
		s=x[c];
	}
	return s;
}
