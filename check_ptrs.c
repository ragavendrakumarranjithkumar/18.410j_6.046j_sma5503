#include<stdio.h>
#include<stdlib.h>
void no_return(int *num_1,int *num_2)
{
	printf("num_1 :%d\n",*num_1);
	printf("num_2 :%d\n",*num_2);
	*num_1=10;
	*num_2=20;
	return;
}
int main()
{
	int *num_1,*num_2;
	num_1=(int*) malloc (sizeof(int));
	num_2=(int*) malloc (sizeof(int));
	*num_1=50;
	*num_2=40;
	printf("num_1 :%d\n",*num_1);
	printf("num_2 :%d\n",*num_2);
	no_return(num_1,num_2);
	printf("num_1 :%d\n",*num_1);
	printf("num_2 :%d\n",*num_2);
	return 0;
}
