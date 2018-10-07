#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (a>b)?a:b
struct node
{
	int data;
	struct node* parent;
	struct node* left;
	struct node* right;
};
struct tree
{
	struct node* root;
	struct node* nil;
};
struct tree *CreateNewTree()
{
	struct tree *newTree;
	struct node *temp;
	newTree=(struct tree*)malloc(sizeof(struct tree));
	newTree->nil=(struct node*)malloc(sizeof(struct node));
	temp=newTree->nil;
	temp->parent=temp->left=temp->right=temp;
	newTree->root=(struct node*)malloc(sizeof(struct node));
	newTree->root=newTree->nil;
	temp=newTree->root;
	temp=temp->parent=temp->left=temp->right=newTree->nil;
	return newTree;
}
struct node *NewNode(struct tree* T,int key)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->parent=T->nil;
	temp->left=T->nil;
	temp->right=T->nil;
	return temp;
}
void insert(struct tree* T, int key)
{
	struct node* y=T->nil;
	struct node* x=T->root;
	struct node* z=NewNode(T,key);
	while(x!=T->nil)
	{
		//printf("%d\n",key);
		y=x;
		if(key>x->data)
			x=x->right;
		else x=x->left;
	}
	z->parent=y;
	if(y==T->nil)
		T->root=z;
	else if(y->data>z->data)
		y->left=z;
	else y->right=z;
}
void inorder(struct tree* T,struct node* root)
{
	if(root!=T->nil)
	{
		inorder(T,root->left);
		printf("%d\t",root->data);
		inorder(T,root->right);
	}
}
void Transplant(struct tree* T,struct node* u,struct node *v)
{
	if(u->parent==T->nil)
		T->root=v;
	else if (u==u->parent->left)
		{
			printf("inside left\n");
			u->parent->left=v;
		}
	else 
		{
			printf("inside right\n");
			u->parent->right=v;
		}
	if(v!=T->nil)
		{
			printf("hello");
			v->parent=u->parent;
		}	
}
struct node* TreeSearch(struct tree * T,int key)
{
	struct node* temp=T->root;
	if(T->root==T->nil)
		{
		printf("T->root==T->nil");
		return T->nil;
		}
	while(temp!=T->nil&&temp->data!=key)
	{
		printf("i\n");
		if(temp->data>key)
			{
			printf("data =%d\n",temp->data);
			temp=temp->left;
			}
		else 
			{
			printf("data =%d\n",temp->data);
			temp=temp->right;
			}
	}
	printf("data =%d\n",temp->data);
	return temp;
}
struct node* TreeMaximum(struct tree* T, struct node* x)
{
	while(x->right!=T->nil)
		x=x->right;
	return x;
}
struct node* TreeMinimum(struct tree* T, struct node* x)
{
	while(x->left!=T->nil)
		x=x->left;
	return x;
}
struct node* TreeSuccessor(struct tree* T, struct node *x)
{
	struct node*y;
	if(x->right!=T->nil)
		return TreeMinimum(T,x->right);
	y=x->parent;
	while(y!=T->nil&&x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
void TreeDelete(struct tree *T,int key)
{
	struct node* y;
	struct node* z=TreeSearch(T,key);
	if(z->left==T->nil)
		Transplant(T,z,z->right);
	else if (z->right==T->nil)
		Transplant(T,z,z->left);
	else 
		{
			y=TreeMinimum(T,z->right);
			if(y->parent!=z)
				{
					Transplant(T,y,y->right);
					y->right=z->right;
					y->right->parent=y;
				}
			Transplant(T,z,y);
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
void Mirror(struct tree* T,struct node* root)
{
	struct node* temp;
	if(T->root==T->nil)
		return;
	else
		{
			temp=root->left;
			root->left=root->right;
			root->right=temp;
			Mirror(T,root->left);
			Mirror(T,root->right);
		}
}
int main()
{
	struct tree *T=CreateNewTree();
	int i=0;
	int a[]={10,5,15,3,7,12,17,1,2,6,8,11,14,16,20};
	for(i=0;i< sizeof(a)/sizeof(int) ;i++ )
	//for (i=0;i<1000;i++)
	insert(T,a[i]);
	//printf("%d\t",T->root->data);
	//printf("%d\t",T->root->right->data);
	//printf("%d\t",T->root->left->data);
	//printf("%d\t",T->root->left->left->data);
	//printf("%d\t",T->root->left->left->right->data);
	printf("%d\t",T->root->left->right->data);
	//printf("%d\t",T->root->left->right->right->right->right->data);
	printf("\n");
	inorder(T,T->root);
	printf("\n");
	//Transplant(T,T->root->left,T->root->right);
	printf("\n");
	inorder(T,T->root);
	printf("\n");
	if(T->nil==TreeSearch(T,8))
		printf("not found\n");
	else printf("found\n");
	printf("maximum =%d\n",(TreeMaximum(T,T->root))->data);
	printf("minimum =%d\n",(TreeMinimum(T,T->root))->data);
	printf("minimum =%d\n",(TreeSuccessor(T,T->root->left))->data);	
	printf("\n");
	inorder(T,T->root);
	printf("\n");
	printf("minimum =%d\n",(TreeSuccessor(T,T->root->right))->data);
	TreeDelete(T,10);
	printf("changed root=%d\n",T->root->data);
	//for(i=0;i< 1000 ;i++ )
	//TreeDelete(T,i);
	printf("\n");
	inorder(T,T->root);
	printf("\n");
	printf("Height of the tree is =%d\n",Height(T,T->root));
	//Mirror(T,T->root);
	return 0;
}
