#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define vertices 10
void enQ(int *Q,int *head,int *tail,int key)
{	
	if(isfull(Q,head,tail))
	{	
		printf("value of head on entering enQ is:%d\t value of tail on entering enQ is:%d\n",*head,*tail);
		printf("Q overflow enQ aboted\n");
		return;
	}
	printf("value of head on entering enQ is:%d\t value of tail on entering enQ is:%d\n",*head,*tail);
	Q[*tail]=key;
	*tail=(*tail+1)%vertices;
	printf("value of head on leaving enQ is:%d\t value of tail on leavingenQ is:%d\n",*head,*tail);
	return;
}
void deQ(int *Q,int* head,int* tail)
{	
	if(isempty(Q,head,tail))
	{
		printf("Q underflow deQ aborted\n");
		return;
	}
	printf("value of head on entering deQ is:%d\t value of tail on entering deQ is:%d\n",*head,*tail);
	Q[*head]=(0);
	*head=(*head+1)%vertices;
	printf("value of head on leaving deQ is:%d\t value of tail on leavingdeQ is:%d\n",*head,*tail);
	return;
}
void printQ(int *Q,int *head,int *tail)
{
	int i=0;
	printf("\nhead is :%d  tail is :%d\n",*head,*tail );
	for(i=0;i<vertices;i++)
	printf("%d\t",*(Q+i));
	printf("\n\n");
}
int isfull(int *Q, int *head, int *tail)
{
	if(((*tail+1)%vertices)==*head)
	return 1;
	else 
	return 0;
}
int isempty(int *Q,int *head, int *tail)
{
	if(*head==*tail)
	return 1;
	else 
	return 0;
}
int main()
{
	int Q[vertices]={0,0,0,0,0,0,0,0,0,0};
	int *head,*tail;
	head=(int*) malloc(sizeof(int));
	tail=(int*) malloc(sizeof(int));
	*head=*tail=0;
	printQ(Q,head,tail);
	deQ(Q,head,tail);
	enQ(Q,head,tail,2);
	enQ(Q,head,tail,3);
	enQ(Q,head,tail,4);
	enQ(Q,head,tail,1);
	enQ(Q,head,tail,6);
	enQ(Q,head,tail,7);
	enQ(Q,head,tail,12);
	enQ(Q,head,tail,10);
	printQ(Q,head,tail);
	enQ(Q,head,tail,5);
	deQ(Q,head,tail);
	printQ(Q,head,tail);
	enQ(Q,head,tail,23);
	deQ(Q,head,tail);
	printQ(Q,head,tail);
	enQ(Q,head,tail,13);
	printQ(Q,head,tail);
	//deQ(Q,head,tail);
	enQ(Q,head,tail,12);
	enQ(Q,head,tail,14);
	enQ(Q,head,tail,17);
}
