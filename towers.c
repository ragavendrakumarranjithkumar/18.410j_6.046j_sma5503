#include<stdio.h>
#include<stdlib.h>
int time=0;
void towers(int n,int from, int to, int spare)
{
	if (n==1)
	{	
		time=time+1;	
		printf("%d>move from: %d to: %d\n",time,from,to);
		return;
	}
	else
	{
		towers(n-1,from,spare,to);
		towers(1,from,to,spare);
		towers(n-1,spare,to,from);
	}
	return;	
}

int main()
{
	towers(4,1,2,0);
	return 0;
}
