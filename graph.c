#include<stdio.h>
#include<stdlib.h>
#define vertices 8
struct node
{
	int key;
	struct node *link;
};
struct node *new_node(int item)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->key=item;
	temp->link=NULL;
	return temp;
}
struct node *insert(struct node* node, int key)
{
	if(node==NULL)
	return new_node(key);
	else if(node!=NULL)
	node->link=insert(node->link,key);
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
	int visited[vertices],length[vertices];
	struct node *adj[vertices];
};
struct graph* new_graph()
{
	int i=0;
	struct graph* temp=(struct graph*) malloc (sizeof(struct graph));
	for(i=0;i<vertices;i++)
	{	
		temp->visited[i]=0;
		temp->length[i]=0;
		(temp->adj[i])=NULL;
	}
	return temp;
}
struct graph* insert_edge(struct graph* graph, int src, int dest)
{	
	if(graph->adj[src]==NULL)
	{
	graph->adj[src]=insert(graph->adj[src],dest);
	graph->length[src]++;
	}
	else 
	{
	insert(graph->adj[src],dest);
	graph->length[src]++;
	}
	return graph;
}
void adjacency_list_print(struct graph* graph)
{
	int i=0;
	for(i=0;i<vertices;i++)
	{
		printf("%d->",i);
		traverse(graph->adj[i]);
		//printf("\tlength of list :%d\n",graph->length[i]);
		printf("\n");
	}
}
struct graph* DFS(struct graph* graph, int v)
{
	printf("%d\t",v);
	graph->visited[v]=1;
	int i=0;
	struct node* head;
	head=graph->adj[v];
	while(head!=NULL)
		{
		if(!graph->visited[head->key])
			DFS(graph,head->key);
		head=head->link;
		}
	return graph;
}
struct graph* visit_reset(struct graph* graph)
{	
	int i=0;
	for(i=0;i<vertices;i++)
	graph->visited[i]=0;
	return graph;
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
		printf("%d\t",temp->key);
		temp=temp->link;
	}
	printf("\n");
	}
	return graph;
}
int main()
{
	struct graph* graph=NULL;
	int visited[8]={0,0,0,0,0,0,0,0};
	graph=new_graph();
	graph=insert_edge(graph,0,3);
	graph=insert_edge(graph,0,4);
	graph=insert_edge(graph,0,2);
	graph=insert_edge(graph,1,0);
	graph=insert_edge(graph,1,3);
	graph=insert_edge(graph,1,2);
	graph=insert_edge(graph,1,6);
	graph=insert_edge(graph,2,5);
	graph=insert_edge(graph,3,1);
	graph=insert_edge(graph,4,2);
	graph=insert_edge(graph,4,6);
	graph=insert_edge(graph,5,6);
	graph=insert_edge(graph,6,4);
	graph=insert_edge(graph,6,7);
	graph=insert_edge(graph,7,5);
	adjacency_list_print(graph);
	//test_adj_list(graph);
	DFS(graph,0);
	printf("\n");
	visit_reset(graph);
	DFS(graph,1);
	printf("\n");
	visit_reset(graph);
	DFS(graph,2);
	printf("\n");
	visit_reset(graph);
	DFS(graph,3);
	printf("\n");
	return 0;
}
