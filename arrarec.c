#include<stdio.h>
int sum(int x[],int size);
int find(int x[],int size,int key);

int main()
{
int arr[10]={1,2,3,4,5,6,7,8,9,10};
printf("sum is :%d\n", sum(arr,9));
printf("ret %d \n",find(arr,10,20));

}

int sum(int x[],int size)
{
if (size==0)
	return x[0];
else
   return x[size]+sum(x,size-1);
}

int find(int x[],int size,int key)
{
if(x[size]==key)
	return 1;
else if(size==0)
	return -1;
else 
	return find(x,size-1,key);


}
