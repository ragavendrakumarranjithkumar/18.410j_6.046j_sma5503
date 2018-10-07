#include<stdio.h>
#include<stdlib.h>
#define n 65
// I dont think an int memo[] is enough to hold values for n>65
//verify output
//find the parent pointers i.e, the actual keystroke sequence to be made
//anyone posing this question would be relly interested in that not the numbers
int memo[n]={};
int max_A(int k)
{
	int b,q;
	if (k<0)
	{
		printf("err:# of keystrokes are negative");
		return -1;
	}
	if(k<=6)
		{
		memo[k]=k;
		return memo[k];
		}
	//comment the following two lines and see how the output slows down for an n=60
	if(memo[k]>0)
		return memo[k];
	else 
	{
		for(b=k-3;b>=0;b--)
		{
			q=(k-b-1)*max_A(b);
			if (q>memo[k])
			memo[k]=q;
			
		}
	}
	return memo[k];
}
int main()
{
	int i;
	for(i=0;i<=n;i++)
	printf("maximum no of A's that can be printed using %d keystrokes are :%d\n",i,max_A(i));
	return 0;
}
