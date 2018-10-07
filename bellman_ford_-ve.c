#include<stdio.h>
#include<stdlib.h>
#define vertices 11
#define infinity 1.0/0.0
#define m_infinity -1.0/0.0
/*****************************************************************************
this program just reports if a -ve weight cycle is found(just like bellman_ford.c). 
it has to find those vertices which are reachable from s through a negative weight
cycle. but it doesn't how to find it ?
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
	int pred[vertices];
	float d[vertices];
	struct node *adj[vertices];
};
struct graph* new_graph()
{
	int i=0;
	struct graph* temp=(struct graph*) malloc (sizeof(struct graph));
	for(i=0;i<vertices;i++)
	{	
		temp->d[i]=infinity;
		temp->pred[i]=-1;	
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
void bellman_ford(struct graph* graph,int source)
{	
	int k=0,i=0,j=0,src,dest,weight,negative_weight_cycle=0;
	struct node* node=NULL;
	for(i=0;i<vertices;i++)
	{
		graph->d[i]=infinity;
		//printf("%f\n",graph->d[i]);
		graph->pred[i]=-1;
	}
	graph->d[source]=0;
	for(j=0;j<vertices-1;j++)
	{
	for(i=0;i<vertices;i++)
	{
	node=graph->adj[i];
	while(node!=NULL)
		{
		src=i;
		dest=node->key;
		weight=node->weight;
		//printf("%d->%d=%d\n",src,dest,weight);
		if((graph->d[dest])>(graph->d[src]+weight))
			{
			//printf("relax %d,%d\n",src,dest);
			graph->d[dest]=(graph->d[src]+weight);
			graph->pred[dest]=src;
			}
		//printf("%d->%d=%f\n",src,dest,graph->d[dest]);
		node=node->link;
		}
	}
	//for(k=0;k<vertices;k++)
	//printf("%d to %d is:%f\n",s,k,graph->d[k]);
	//printf("end of iteration %d\n",j);
	}
	for(i=0;i<vertices;i++)
	{
	node=graph->adj[i];
	while(node!=NULL)
		{
		if((graph->d[node->key])>(graph->d[i]+node->weight))
		{
		printf("node %d is recahble from a -ve weight cycle\n",node->key);
		negative_weight_cycle=1;
		}
		node=node->link;
		}
	}
	if(negative_weight_cycle)
	printf("graph has a -ve weight cycle\n");
	else
	{
		for(i=0;i<vertices;i++)
		{
		printf("shortest path from %d to %d is:%f\n",source,i,graph->d[i]);
		printf("predecessor of %d is %d\n",i,graph->pred[i]);
		}
	}
}
void relax(struct node* graph)
{
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
	graph=insert_edge(graph,0,1,3);
	graph=insert_edge(graph,0,3,5);
	graph=insert_edge(graph,0,6,2);
	graph=insert_edge(graph,3,4,6);
	graph=insert_edge(graph,1,2,-4);
	graph=insert_edge(graph,2,5,4);
	graph=insert_edge(graph,4,3,-3);
	graph=insert_edge(graph,4,5,8);
	graph=insert_edge(graph,7,5,7);
	graph=insert_edge(graph,6,7,3);
	graph=insert_edge(graph,7,6,-6);
	graph=insert_edge(graph,8,9,2);
	graph=insert_edge(graph,10,8,-8);
	graph=insert_edge(graph,9,10,3);
	adjacency_list_print(graph);
	bellman_ford(graph,0);
	//test_adj_list(graph);
	return 0;
}
