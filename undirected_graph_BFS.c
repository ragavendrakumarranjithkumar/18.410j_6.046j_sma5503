#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define vertices 16
#define infinity 1.0/0.0
#define m_infinity -1.0/0.0
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
struct queque
{
	int q[vertices];
	int *head,*tail;
};
struct queque* new_queque()
{
	int i=0;
	struct queque* Q=(struct queque*) malloc (sizeof(struct queque));
	for(i=0;i<vertices;i++)
		Q->q[i]=-1;
	Q->head=(int*)malloc(sizeof(int));
	Q->tail=(int*)malloc(sizeof(int));
	return;
}
void printQ(struct queque* Q)
{
	printf("head: %d tail: %d\n",*(Q->head),*Q->tail);
	int i=0;
	for(i=0;i<vertices;i++)
	printf("%d\t",Q->q[i]);
	printf("\n");
}
struct queque* enQ(struct queque* Q,int key)
{
	if((*(Q->tail)+1)%vertices==*(Q->head))
	{
		printf("queque full enQ aborted\n");
		return Q;
	}
	else
	{
		Q->q[*(Q->tail)]=key;
		*(Q->tail)=(*(Q->tail)+1)%vertices;
		return Q;
	}
}
int deQ(struct queque * Q)
{	
	int temp;
	if(*(Q->head)==*(Q->tail))
	{
		printf("queque empty deQ aborted\n");
		return 0;
	}
	else
	{
		temp=Q->q[*(Q->head)];
		Q->q[*(Q->head)]=-1;
		*(Q->head)=(*(Q->head)+1)%vertices;
		return temp;
	}
}
int isQempty(struct queque * Q)
{
	return (*(Q->head)==*(Q->tail));
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
	int visited[vertices],length[vertices],color[vertices],pred[vertices];
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
		temp->pred[i]=0;
		temp->color[i]=1;
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
struct graph* BFS(struct graph* graph,struct queque* Q, int s)
{
	int u,v;
	struct node* head;
	graph->color[s]=2;
	graph->d[s]=0;
	graph->pred[s]=-1;
	enQ(Q,s);
	//printQ(Q);
	while(!isQempty(Q))
		{
			u=deQ(Q);
			//printQ(Q);
			head=graph->adj[u];
			while(head!=NULL)
			{
			v=head->key;
			if(graph->color[v]==1)
			{	
				graph->color[v]=2;
				graph->d[v]=graph->d[u]+1;
				graph->pred[v]=u;
				enQ(Q,v);
				//printQ(Q);
			}
			head=head->link;
			}
			graph->color[u]=0;
		}
	return graph;
}
int main()
{	
	struct queque* Q=NULL;;
	Q=new_queque();
	printQ(Q);
	struct graph* graph=NULL;
	int i=0;
	graph=new_graph();
	graph=insert_edge(graph,0,1);
	graph=insert_edge(graph,0,4);
	graph=insert_edge(graph,0,5);
	graph=insert_edge(graph,4,5);
	graph=insert_edge(graph,8,9);
	graph=insert_edge(graph,4,8);
	graph=insert_edge(graph,5,8);
	graph=insert_edge(graph,6,9);
	graph=insert_edge(graph,10,9);
	graph=insert_edge(graph,6,3);
	graph=insert_edge(graph,2,3);
	graph=insert_edge(graph,11,15);
	graph=insert_edge(graph,2,6);
	graph=insert_edge(graph,1,2);
	graph=insert_edge(graph,5,1);
	graph=insert_edge(graph,10,6);
	graph=insert_edge(graph,11,6);
	graph=insert_edge(graph,12,13);
	graph=insert_edge(graph,8,13);
	graph=insert_edge(graph,12,8);
	graph=insert_edge(graph,13,10);
	graph=insert_edge(graph,14,10);
	graph=insert_edge(graph,3,7);
	graph=insert_edge(graph,7,11);
	adjacency_list_print(graph);
	BFS(graph,Q,0);
	for(i=0;i<vertices;i++)
	{
		printf("predecessor,color,distance of vetex %d:%d %d %f\n",i,graph->pred[i],graph->color[i],graph->d[i]);
	}
	//test_adj_list(graph);
	/*
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
	*/
	return 0;
}
