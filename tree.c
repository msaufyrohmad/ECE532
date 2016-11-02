/*
 * Code for Binary Search Tree Operation using linked list
 *
 * Computer Engineering UiTM
 * Muhammad Saufy Rohmad
 *
 */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
}*root;

struct node* alloc(int);
void insert(struct node *,struct node*);
void read();
struct node* search(struct node*,int val);
int found=0;
void inorder(struct node *);

struct node* alloc(int n)
{
	struct node *nw;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=n;
	nw->left=NULL;
	nw->right=NULL;
}


void read()
{
	struct node* temp=root;
	while(temp)
	{
		printf("inside is %d \n",temp->data);
		temp=temp->left;
	}
	
}

void insert(struct node *root,struct node *x)
{
	printf(" root,x and value x: %u :  %d %u \n",root,x->data,x);
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

struct node* search(struct node *root,int val)
{
	if(root)
	{
	if(val<root->data)
		search(root->left,val);
	else if (val>root->data)
		search(root->right,val);
	else if(val==root->data)  
		return root;
	}
}

struct node* searchparent(struct node* root,struct node *s)
{
	if(root)
	{
		if(root==s)
			return root;
		searchparent(root->left,s);
		searchparent(root->right,s);
	}
}

void del(struct node *root,int val)
{
	struct node *temp,*temp2;
	temp=search(root,val);
	if(temp->left==NULL && temp->right==NULL)
	{
		printf("This node dont have left and right child!\n");
		temp2=searchparent(root,temp);
		free(temp);
		if(temp2->left==temp)temp2->left=NULL;
		else temp2->right=NULL;
	}
	if(temp->left!=NULL && temp->right==NULL)
	{
		printf("This node have left child but without right child!\n");
		/*
 		*
 		* TODO
 		*/ 	
	}
	if(temp->left==NULL && temp->right!=NULL)
	{
		printf("This dont node have left child but have right child!\n");
		/*
 		* TODO
 		*
 		*/  	
	}
	if(temp->left!=NULL && temp->right!= NULL)
	{
		printf("This node have left and right child!\n");
		temp2=searchparent(root,temp);
		/*
 		* TODO
 		*
 		*/  

	}
}

void inorder(struct node *root)
{
	printf("ROOT DEBUG %u \n",root);
	if(root)
	{
		inorder(root->left);
		printf("READ %d at %u\n",root->data,root);
		inorder(root->right);
	}
}

void preorder(struct node *root)
{
	printf("ROOT DEBUG %u \n",root);
	if(root)
	{
		printf("READ %d \n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	printf("ROOT DEBUG %u \n",root);
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("READ %d \n",root->data);
	}
}

int main()
{
	struct node *realroot;
	struct node* r=NULL;
	struct node *x=alloc(10);
	struct node *y=alloc(5);
	struct node *z=alloc(14);
	struct node *a=alloc(17);
	struct node *b=alloc(12);
	struct node *c=alloc(2);
	struct node *d=alloc(7);

	struct node *e=alloc(1);
	struct node *f=alloc(3);
	struct node *g=alloc(6);
	struct node *h=alloc(9);
	struct node *i=alloc(11);
	struct node *j=alloc(13);
	struct node *k=alloc(15);
	struct node *l=alloc(20);
	if(root==NULL)
	{
		root=x;
		realroot=x;
		printf("ROOT ADD: %u \n",root);
	}
	else
		insert(root,x);
	insert(root,y);
	insert(root,z);
	insert(root,a);
	insert(root,b);
	insert(root,c);
	insert(root,d);
	insert(root,e);
	insert(root,f);
	insert(root,g);
	insert(root,h);
	insert(root,i);
	insert(root,j);
	insert(root,k);
	insert(root,l);
	r=search(realroot,14);
	if(r)	
		printf("%d found! \n",r->data);
	else
		printf("NOT FOUND! \n");


	printf("====================== \n");
	inorder(realroot);
	printf("====================== \n");
	preorder(realroot);
	printf("====================== \n");
	postorder(realroot);
	del(realroot,20);
	inorder(realroot);
}
