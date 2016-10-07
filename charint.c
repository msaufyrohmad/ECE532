#include<stdio.h>
int count(char a[],int size);
void demo(char a[],int size);
int main()
{
char a[10]="Muhammad";
demo(a,10);
printf("TOTAL %d \n",count(a,10));
}

int count(char a[],int size)
{
	if(size==0)
		return (int)a[0];
	else
		return (int)a[size]+count(a,size-1);
}

void demo(char a[],int size)
{
	int x;
	for(x=0;x<10;x++)
	printf("%d ",a[x]);
}
