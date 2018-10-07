#include<stdio.h>
#include<stdlib.h>
#define no_m 6
#define no_m_d (no_m+1)
#define inf 1.0/0.0
float memo[no_m][no_m]={};
//passing two dimnesinal arrays to functions was really annoying so I'm
//doing this bad habit. please learn how to pass 2D arrays to functions
void compute_base_cases(int *D)
{
	int i,j=0;
	for(i=0;i<no_m;i++)
	{
		for(j=0;j<no_m;j++)
		memo[i][j]=inf;
	}
	//these for loops are run upto no_m-1 so as to prevent inapropriate
	//indexing when i=j=6
	for(i=0;i<no_m-1;i++)
	{
		for(j=0;j<no_m-1;j++)
		if(i==j)
		{	
			memo[i][j]=0;
			memo[i][j+1]=memo[i+1][j]=D[j]*D[j+1]*D[j+2];
		}
	}
	for (i=0;i<no_m;i++)
	{	
		for (j=0;j<no_m;j++)
		printf("%f\t",memo[i][j]);
		printf("\n");
	}
	return;
}
int matrix_chain_multiply(int i, int j, int* D)
{	
	printf("matrix_chain called for i=%d,j=%d\n",i,j);
	int k,q;
	if (i+1==j)
		return memo[i][j];
	if (memo[i][j]<inf)
		return memo[i][j];
	if (i==j)
	//this is necassary so as to split (0..5) as (0,1..5),(0..1,2..5) and so on
	//the first split(0,1..5) needs this condition
	//this essentially means that a single matrix has been ruled out to be multtiplied 
		return 0;
	else
	{
		for(k=i;k<j;k++)
		{	
			printf("chain split:%d..%d,%d..%d\n",i,k,k+1,j);
			// a split of  Ai..Ak   ,  Ak+1..Aj
			//dimensions  (i x K+1) * (K+1 x j+1)
			int q=matrix_chain_multiply(i,k,D)
				+matrix_chain_multiply(k+1,j,D)+(D[i]*D[k+1]*D[j+1]);
			if(q<memo[i][j])
			memo[i][j]=q;
		}
		return memo[i][j];
	}
}
int main()
{
	int D[no_m+1]={30,35,15,5,10,20,25};
//i'th matrix has dimension i x i+1
//thus if  a multiplication of matrices chain (Ai...Ak)*(Ak+1...Aj) takes place
//the dimensions of (i'th matrix at begining...k'th matrix at end)
//		    (I x i+1 X .........................X k x K+1)
//the dimensions of (k+1'st matrix at begging...j'th matrix at end)
//		    (K+1 x K+2 x ....................... x j x J+1)
//thus    (i...k+1)*(k+1...j+1)
//costs me i*k+1*j+1
	int i,j=0;
	for (i=0;i<no_m;i++)
	{	
		for (j=0;j<no_m;j++)
		printf("%f\t",memo[i][j]);
		printf("\n");
	}
	for (i=0;i<no_m;i++)
	printf("dimension of %d matrix is %dx%d\n",i,D[i],D[i+1]);
	printf("total no of matrices are : %d\n",no_m);
	compute_base_cases(D);
	printf("%d\n",matrix_chain_multiply(0,no_m-1,D));
	printf("minimum no of multiplications required are: %f",memo[0][no_m-1]);
	printf("\n");
	for (i=0;i<no_m;i++)
	{	
		for (j=0;j<no_m;j++)
		printf("%f\t",memo[i][j]);
		printf("\n");
	}
	return 0;
}
