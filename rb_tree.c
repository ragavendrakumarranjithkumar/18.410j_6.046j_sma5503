#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
typedef struct rbnode rbnode;
typedef struct rbtree rbtree;
rbtree* CreateNewTree(void);
rbnode* CreateNewNode(rbtree* ,int );
void Insert(rbtree* ,int );
void LeftRotate(rbtree* ,rbnode* );
void RightRotate(rbtree* ,rbnode* );
void RBInsertFixup(rbtree* , rbnode* );
void Inoder(rbtree* , rbnode*);
int Height(rbtree* t,rbnode* root);
struct rbnode
{
	int data;
	int color;
	rbnode *parent,*left,*right;
};
struct rbtree 
{
	rbnode *root;
	rbnode *nil;
};
rbtree* CreateNewTree()
{
	rbtree* newTree;
	rbnode* temp;
	newTree=(rbtree*)malloc(sizeof(rbtree));
	temp=newTree->nil=(rbnode*)malloc(sizeof(rbnode));
	temp->parent=temp->left=temp->right=temp;
	temp->color=0;
	temp=newTree->root=(rbnode*)malloc(sizeof(rbnode));
	temp->parent=temp->left=temp->right=newTree->nil;
	temp->color=0;
	newTree->root=newTree->nil;
	return newTree;
}
rbnode* CreateNewNode(rbtree* t,int key)
{
	rbnode* temp;
	temp=(rbnode*)malloc(sizeof(rbnode));
	temp->parent=temp->left=temp->right=t->nil;
	temp->data=key;
	temp->color=1;
	return temp;
}
void Insert(rbtree* t,int key)
{
	rbnode* z=CreateNewNode(t,key);
	rbnode* y=t->nil;
	rbnode* x=t->root;
	while(x!=t->nil)
	{
		y=x;
		if(x->data>key)
			x=x->left;
		else x=x->right;
	}
	z->parent=y; /*this happens always i.e, without having to check for a condition */
	if(y==t->nil)
		t->root=z;
	else if(y->data>z->data)
		y->left=z;
	else y->right=z;
	RBInsertFixup(t,z);	
}
void LeftRotate(rbtree* t,rbnode* x)
{
	rbnode* y=x->right;
	x->right=y->left;
	if(y->left!=t->nil)
		y->left->parent=x;
	y->parent=x->parent; /*this happens always i.e, without having to check for a condition */
	if(x->parent==t->nil)
		t->root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else x->parent->right=y;
	y->left=x;
	x->parent=y;
}
void RightRotate(rbtree* t,rbnode* x)
{
	rbnode* y=x->left;
	x->left=y->right;
	if(y->right!=t->nil)
		y->right->parent=x;
	y->parent=x->parent; /*this happens always i.e, without having to check for a condition */
	if(x->parent==t->nil)
		t->root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else x->parent->right=y;
	y->right=x;
	x->parent=y;
}
void RBInsertFixup(rbtree* t, rbnode* z)
{
	rbnode* y;
	while(z->parent->color==1)
	{
		if(z->parent==z->parent->parent->left)
			{
				y=z->parent->parent->right;
				if(y->color==1)
				{
					z->parent->color=0;
					y->color=0;
					z->parent->parent->color=1;
					z=z->parent->parent;
				}
				else 
				{	
					if (z==z->parent->right)
					{
						z=z->parent;
						LeftRotate(t,z);
					}
					z->parent->color=0;
					z->parent->parent->color=1;
					RightRotate(t,z->parent->parent);
				}
			}	
		else 
			{
				y=z->parent->parent->left;
				if(y->color==1)
				{
					z->parent->color=0;
					y->color=0;
					z->parent->parent->color=1;
					z=z->parent->parent;
				}
				else 
				{	
					if (z==z->parent->left)
					{
						z=z->parent;
						RightRotate(t,z);
					}
					z->parent->color=0;
					z->parent->parent->color=1;
					LeftRotate(t,z->parent->parent);
				}
			}	
	}
	t->root->color=0;		
}
void Inorder(rbtree* t, rbnode* root)
{
	if(root!=t->nil)
	{
		Inorder(t,root->left);
		printf("%d ",root->data);
		if(root->color==1)
		printf("red\n");
		else printf("black\n");
		Inorder(t,root->right);
	}
}
int Height(rbtree* t,rbnode* root)
{
	int l_height,r_height;
	if(root==t->nil)
		return 0;
	else
		{
			l_height=Height(t,root->left);
			r_height=Height(t,root->right);
			if(l_height>r_height)
				return (l_height+1);
			else return r_height+1;
		}
}
int main()
{
	int i=0;
	int a[]={1,10,25,50,48,9,8,7,26,46};
	rbtree* T=CreateNewTree();
	for(i=0;i<((sizeof(a))/(sizeof(int)));i++)
	Insert(T,a[i]);
	Inorder(T,T->root);
	printf("\n");
	printf("rbtree height=%d\n",Height(T,T->root));
	return 0;
}
