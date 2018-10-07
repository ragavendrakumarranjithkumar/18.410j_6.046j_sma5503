#include<stdio.h>
#include<stdlib.h>
/***********************************************************************
this progroam was writtten with an intention  to  implement  deQ and enQ 
operations on a doubly_linked_list
***********************************************************************/
struct node
{
	int key;
	struct node* prev;
	struct node* next;
};
struct node* new_node(struct node* pred, int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->prev=pred;
	temp->next=NULL;
	return temp;
}
struct node* insert(struct node* x,struct node *y, int item)
{
	if (y==NULL)
	return new_node(x,item);
	else
	y->next=insert(y,y->next,item);
	return y;
}
void traverse(struct node *head)
{
	if (head==NULL)
	return;
	else if(head!=NULL)
	{
		printf("%d\t",head->key);
		printf("%u\t%u\n",head->next,head->prev);
		traverse(head->next);
	}
}
int main()
{
	struct node* head=NULL;
	head=insert(head,head,50);
	insert(head,head,40);
	insert(head,head,30);
	insert(head,head,20);
	insert(head,head,10);
	insert(head,head,70);
	insert(head,head,80);
	insert(head,head,90);
	traverse(head);
	return 0;
}
