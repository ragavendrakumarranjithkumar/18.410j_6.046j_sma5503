#include<stdio.h>
#include<stdlib.h>
#define vertices 5
/*****************************************************************************
this is just a prototype of a weighted directed graph that is needed for 
bellman ford. this structure is used in the bellman_ford.c file to compute
shotest paths.
*****************************************************************************/
struct node
{
	int key,weight;
	struct node *link;
};
struct node *new_node(int item,int weight)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->key=item;
	temp->weight=weight;
	temp->link=NULL;
	return temp;
}
struct node *insert(struct node* node, int key,int weight)
{
	if(node==NULL)
	return new_node(key,weight);
	else if(node!=NULL)
	node->link=insert(node->link,key,weight);
	return node;
}
void traverse(struct node *head)
{
	if (head==NULL)
	return;
	else if(head!=NULL)
	{
		printf("%d->",head->key);
		traverse(head->link);
	}
}
struct graph
{	
	int d[vertices],pred[vertices];
	struct node *adj[vertices];
};
struct graph* new_graph()
{
	int i=0;
	struct graph* temp=(struct graph*) malloc (sizeof(struct graph));
	for(i=0;i<vertices;i++)
	{	
		(temp->adj[i])=NULL;
	}
	return temp;
}
struct graph* insert_edge(struct graph* graph, int src, int dest, int weight)
{	
	if(graph->adj[src]==NULL)
	graph->adj[src]=insert(graph->adj[src],dest,weight);
	else 
	insert(graph->adj[src],dest,weight);
	return graph;
}
void adjacency_list_print(struct graph* graph)
{
	int i=0;
	for(i=0;i<vertices;i++)
	{
		printf("%d->",i);
		traverse(graph->adj[i]);
		printf("\n");
	}
}
void bellman_ford(struct graph* graph,int s)
{	
	int i=0;
	struct node* node=NULL;
	for(i=0;i<vertices;i++)
	{
	node=graph->adj[i];
	while(node!=NULL)
		{
		printf("the edge from %d->%d has weight%d\n",i,node->key,node->weight);
		node=node->link;
		}
	}
}
struct graph* test_adj_list(struct graph* graph)
{
	int i=0;
	struct node* temp;
	for(i=0;i<vertices;i++)
	{
	temp=graph->adj[i];
	while(temp!=NULL)
	{
		printf("%d->%d =%d\t ",i,temp->key,temp->weight);
		temp=temp->link;
	}
	printf("\n");
	}
	return graph;
}
int main()
{
	struct graph* graph=NULL;
	graph=new_graph();
	graph=insert_edge(graph,0,1,6);
	graph=insert_edge(graph,0,3,7);
	graph=insert_edge(graph,4,2,7);
	graph=insert_edge(graph,1,4,-4);
	graph=insert_edge(graph,3,4,9);
	graph=insert_edge(graph,1,2,5);
	graph=insert_edge(graph,2,1,-2);
	graph=insert_edge(graph,1,3,8);
	graph=insert_edge(graph,3,2,-3);
	graph=insert_edge(graph,4,0,2);
	//adjacency_list_print(graph);
	//bellman_ford(graph,1);
	test_adj_list(graph);
	return 0;
}
