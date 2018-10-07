#include<stdio.h>
#include<stdlib.h>
#define vertices 5
/**************************************************************
this program is a continuation of array_of_pointers.c in code_2
here we have  a  struct  graph  holding an array of pointers to 
intergers. rest of the implementation is the same
23: temp=(struct graph*) malloc (sizeof(struct graph));
this statement is very important  as we are  allocating memeory 
to temp in this  statement  memeory  allocation must proceed as
follows 
1> stuct graph* temp;
2> array of pointers within struct temp
**************************************************************/
struct graph
{
int *adj[vertices];
};
struct graph* new_graph()
{
int i=0;
struct graph* temp;
temp=(struct graph*) malloc (sizeof(struct graph));
for(i=0;i<vertices;i++)
(temp->adj[i])=(int *) malloc(sizeof(int));
*(temp->adj[0])=10;
*(temp->adj[3])=80;
printf("%d\n",*(temp->adj[0]));
printf("%d\n",*(temp->adj[3]));
return temp;
}
int main()
{
struct graph* graph;
graph=new_graph();
return 0;
}
