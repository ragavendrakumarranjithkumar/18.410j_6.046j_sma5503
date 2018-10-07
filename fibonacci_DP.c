#include<stdio.h>
#include<stdlib.h>
#define number 45
/*
DYNAMIC PROGRAMMING - I this program computes the n'th fibonacci number
in O(n) time using  dynamic  programming recursion + memoization (here)
*/
int fib[number]={};
//fib is the global array storing the MEMO
int fibonacci(int n)
{	
	if (fib[n]!=0)
		return fib[n];
	else if (n<=2)
		{
		fib[n]=1;
		return fib[n];
		}
	else
		{
		fib[n-1]=fibonacci(n-1);
		fib[n-2]=fibonacci(n-2);
		//values are stored in MEMO before returning from function
		return (fib[n-1]+fib[n-2]);
		}
}
int main()
{	
	int i=0;
	printf("the %d'th fibonacci number is:%d\n",number,fibonacci(number));
	for(i=0;i<number;i++)
	printf("%d\n",fib[i]);
	return 0;
}
