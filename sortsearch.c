/*
 *Sorting and Searching Algorithms in C
 *
 * O(n^2)
 * Bubble
 * Insertion
 * Selection
 *
 * O(log n)
 * Binary Tree
 * Quick
 * Merge
 * 
 * O(n^2)
 * Sequential
 *
 * O(log n)
 * Binary Search 
 *
 * Computer Engineering
 * UiTM Shah Alam
 *
 * Muhammad Saufy Rohmad 
 *
 */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int arr[SIZE];
struct node 
{
	int data;
	struct node *left;
	struct node *right;
}*root;

void generate();

void bubble(int arr[],int n);
void insertion(int arr[],int n);
void selection(int arr[],int n);

void quick(int A[],int ,int );
int partition(int A[SIZE],int low,int high);
void swap(int A[SIZE],int *i,int *j);

void mergesort(int arr[],int ,int );
void merge(int arr[],int ,int ,int ,int);

void binarytree(int arr[],int );
void insert(struct node *root,struct node *x);
void inorder(struct node *tree);

int linearsearch(int s);
int binarysearch(int s);

void read();

int main()
{
	generate();
	printf("\n === BUBBLE === \n");
	bubble(arr,SIZE);
	read();	

	generate();
	printf("\n === INSERTION === \n");
	insertion(arr,SIZE);
	read();

	generate();
	printf("\n === SELECTION === \n");
	insertion(arr,SIZE);
	read();
	
	generate();
	printf("\n === QUICK === \n");
	quick(arr,0,SIZE);
	read();
	
	generate();
	printf("\n === MERGE === \n");
	mergesort(arr,0,SIZE-1);
	read();
	
	generate();
	printf("\n === BINARY TREE === \n");
	binarytree(arr,SIZE);
	inorder(root);

	printf("\n === LINEAR SEARCH === \n");
	int s=rand()%10000;
	if(linearsearch(s))printf(" %d found on array! \n",s);
	else printf("%d not found! \n",s);
	
	printf("\n === BINARY SEARCH === \n");
	int x=rand()%10000;
	if(binarysearch(x))printf(" %d found on array! \n",x);
	else printf("%d not found! \n",x);
}

void generate()
{

	int x;
	printf("\n === GENERATE RANDOM ARRAY ===\n");
	for(x=0;x<SIZE;x++)
	{
		arr[x]=rand()%10000;
		printf("%d ",arr[x]);
	}
}

void read()
{
	int i;
	for(i=0;i<SIZE;i++)
	printf("%d ",arr[i]);
}

void bubble(int a[],int n)
{

	int i,j,m,temp;
	for (i=0;i<n-1;i++)
	{
	for (j=0;j<n;j++)
	{
		if(a[j]>a[j+1])
		{
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}
	}
	}
}	

void insertion(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n-1;i++)
	{
		temp=a[i];
		j=i-1;
		while((j>=0)&&(a[j]>temp))
		{
		a[j+1]=a[j];
		j=j-1;
		}
	a[j+1]=temp;
	}
}

void selection(int a[10],int n)
{
	int i,j,min,temp;
	for(i=0;i<=n-2;i++)
	{
	min=i;
	for(j=i+1;j<=n-1;j++)
	{
	if(a[j]<a[min])
		min=j;
	}
	temp=a[i];
	a[i]=a[min];
	a[min]=temp;
	}
}

void quick(int A[SIZE],int low,int high)
{
	int m,i;
	if(low<high)
	{
		m=partition(A,low,high);
		quick(A,low,m-1);
		quick(A,m+1,high);
	}
}
int partition(int A[SIZE],int low,int high)
{
	int pivot=A[low],i=low,j=high;
	while(i<=j)
	{
	 while(A[i]<=pivot)
	i++;
	while(A[j]>pivot)
	j--;
	if(i<j)
	swap(A,&i,&j);
	}
	swap(A,&low,&j);
	return j;
}

void swap(int A[SIZE],int *i,int *j)
{
	int temp;
	temp=A[*i];
	A[*i]=A[*j];
	A[*j]=temp;
}

void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[SIZE];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
       for(i=i1,j=0;i<=j2;i++,j++)
               a[i]=temp[j];
}

void binarytree(int arr[],int n)
{
	int x;
	if(root==0)
	{
		struct node *n=(struct node*)malloc(sizeof(struct node));
		n->data=arr[0];
		n->left=NULL;
		n->right=NULL;
		root=n;
	}
	for(x=1;x<n;x++)
	{
		struct node *n=(struct node *)malloc(sizeof(struct node));
		n->data=arr[x];
		n->left=NULL;
		n->right=NULL;
		insert(root,n);
	}
}

void insert(struct node *root,struct node *x)
{
        if(x->data<root->data)
        {
                if(root->left==NULL)
                        root->left=x;
                else
                        insert(root->left,x);
        }
        else
        {
                if(root->right==NULL)
                        root->right=x;
                else
                        insert(root->right,x);
        }
}

void inorder(struct node *root)
{
        if(root)
        {
                inorder(root->left);
                printf("%d ",root->data);
                inorder(root->right);
        }
}

int linearsearch(int s)
{
	int x;
	for(x=0;x<SIZE;x++)
	{
		if(arr[x]==s)
			return 1;
	}
	return 0;
}

int binarysearch(int search)
{
   int c,first,last,middle,n;
 
   first = 0;
   last = SIZE - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (arr[middle] < search)
         first = middle + 1;    
      else if (arr[middle] == search) {
        // printf("%d found at location %d.\n", search, middle+1);
        return 1; 
	break;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   if (first > last)
     // printf("Not found! %d is not present in the list.\n", search);
 
   return 0;   
}




