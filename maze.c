#include<stdio.h>
#include<stdlib.h>
#define vertices 36
#define goal 14
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
struct graph* insert_edge(struct graph* graph, int ep_1, int ep_2)
{	
	if(graph->adj[ep_1]==NULL)
	{
	graph->adj[ep_1]=insert(graph->adj[ep_1],ep_2);
	graph->length[ep_1]++;
	}
	else 
	{
	insert(graph->adj[ep_1],ep_2);
	graph->length[ep_1]++;
	}
	if(graph->adj[ep_2]==NULL)
	{
	graph->adj[ep_2]=insert(graph->adj[ep_2],ep_1);
	graph->length[ep_2]++;
	}
	else 
	{
	insert(graph->adj[ep_2],ep_1);
	graph->length[ep_2]++;
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
struct graph* DFS_maze(struct graph* graph, int v)
{
	int i=0;
	printf("%d\t",v);
	graph->visited[v]=1;
	if(v==goal)
	{
	for(i=0;i<vertices;i++)
	graph->visited[i]=1;
	return graph;
	}
	struct node* head;
	head=graph->adj[v];
	while(head!=NULL)
		{
		if(!graph->visited[head->key])
			DFS_maze(graph,head->key);
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
	graph=new_graph();
	graph=insert_edge(graph,0,1);
	graph=insert_edge(graph,1,2);
	graph=insert_edge(graph,2,8);
	graph=insert_edge(graph,8,14);
	graph=insert_edge(graph,14,13);
	graph=insert_edge(graph,13,12);
	graph=insert_edge(graph,12,6);
	graph=insert_edge(graph,6,7);
	graph=insert_edge(graph,12,18);
	graph=insert_edge(graph,18,24);
	graph=insert_edge(graph,24,30);
	graph=insert_edge(graph,30,31);
	graph=insert_edge(graph,31,32);
	graph=insert_edge(graph,32,33);
	graph=insert_edge(graph,33,27);
	graph=insert_edge(graph,27,21);
	graph=insert_edge(graph,21,15);
	graph=insert_edge(graph,15,9);
	graph=insert_edge(graph,9,3);
	graph=insert_edge(graph,3,4);
	graph=insert_edge(graph,4,10);
	graph=insert_edge(graph,10,16);
	graph=insert_edge(graph,16,17);
	graph=insert_edge(graph,17,11);
	graph=insert_edge(graph,11,5);
	graph=insert_edge(graph,17,23);
	graph=insert_edge(graph,23,22);
	graph=insert_edge(graph,22,28);
	graph=insert_edge(graph,28,29);
	graph=insert_edge(graph,29,35);
	graph=insert_edge(graph,35,34);
	graph=insert_edge(graph,21,20);
	graph=insert_edge(graph,20,26);
	graph=insert_edge(graph,26,25);
	graph=insert_edge(graph,25,19);
	adjacency_list_print(graph);
	//test_adj_list(graph);
	DFS_maze(graph,0);
	printf("\n");
	visit_reset(graph);
	return 0;
}
