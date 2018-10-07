#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
typedef struct node node;
typedef struct tree tree;
struct node
{
	int data;
	node* left,*right,*parent;
};
struct tree
{
	node* root;
	node* nil;
};
tree* CreateNewTree()
{
	tree* newTree;
	node *temp;
	newTree=(tree*)malloc(sizeof(tree));
	newTree->nil=(node*)malloc(sizeof(node));
	temp=newTree->nil;
	temp->parent=temp->left=temp->right=temp;
	newTree->root=(node*)malloc(sizeof(node));
	newTree->root=newTree->nil;
	temp=newTree->root;
	temp->left=temp->parent=temp->right=newTree->nil;
	return newTree;
}
node * CreateNewNode(tree* t,int key)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=key;
	temp->parent=temp->left=temp->right=t->nil;
	return temp;
}
void insert(tree* t,int key)
{
	node* z=CreateNewNode(t,key);
	node* y=t->nil;
	node *x=t->root;
	while(x!=t->nil)
	{
		y=x;
		if(key>x->data)
			x=x->right;
		else x=x->left;
	}
	if(y==t->nil)
		t->root=z;
	z->parent=y;
	if(y->data>z->data)
		y->left=z;
	else y->right=z;
}
void Inorder(tree* t, node* root)
{
	if(root!=t->nil)
	{
		Inorder(t,root->left);
		printf("%d\t",root->data);
		Inorder(t,root->right);
	}
}
node* TreeSearch(tree* t,int key)
{
	node* y=t->root; 
	while(y!=t->nil&&y->data!=key)
	{
		if(y->data>key)
			y=y->left;
		else y=y->right;
	}
	return y;
}
node* TreeMinimum(tree* t,node *x)
{
	while(x->left!=t->nil)
		x=x->left;
	return x;
}
node* TreeMaximum(tree* t,node *x)
{
	while(x->right!=t->nil)
		x=x->right;
	return x;
}
node *TreeSuccessor(tree *t,node *x)
{
	node* y;
	if(x->right!=t->nil)
		return TreeMinimum(t,x->right);
	y=x->parent;
	while(y!=t->nil&&y->right==x)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
void Transplant(tree* t,node *u,node *v)
{
	if(u->parent==t->nil)
		t->root=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else u->parent->right=v;
	if(v!=t->nil)
		v->parent=u->parent;
}
void Delete(tree *t,int key)
{
	node *z=TreeSearch(t,key);
	node *y;
	if(z==t->nil)
		return;
	else if(z->right==t->nil)
		Transplant(t,z,z->left);
	else if(z->left==t->nil)
		Transplant(t,z,z->right);
	else 
		{
			y=TreeMinimum(t,z->right);
			if(y!=z->right)
				{
					Transplant(t,y,y->right);
					y->right=z->right;
					y->right->parent=y;
				}
			Transplant(t,z,y);
			y->left=z->left;
			y->left->parent=y;
		}
}
int Height(struct tree* T,struct node* root)
{
	int l_height,r_height;
	if(root==T->nil)
		return 0;
	else
		{
			l_height=Height(T,root->left)+1;
			r_height=Height(T,root->right)+1;
			return max(l_height,r_height);
		}	
}
int main()
{
	int i=0;
	int a[]={10,6,17,4,13,8,12,15,1};
	tree* T=CreateNewTree();
	for(i=0;i<1000;i++)
	insert(T,i);
	Inorder(T,T->root);
	printf("\n");
	printf("BST height=%d\n",Height(T,T->root));
	return 0;	
}
