#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 1.0/0.0
#define min(x,y,z) ((z<((x<y)?x:y))?z:((x<y)?x:y))
/*enter two strings in driver (main)
comment the call compute_base_cases(x,y)
get the distance printed at the console
change the dimensions of memeo as [length_of_first_sting +1][length_of_second_sting +1]
example
string length of "" is 7
string length of "" is 5
memo[8][5] 
*/
float memo[7][8]={};
void compute_base_cases(char *x,char *y)
{
	int i,j=0;
	for (i=0;i<strlen(x);i++)
	{
		for(j=0;j<strlen(y);j++)
		memo[i][j]=inf;
	}
	for (i=0,j=strlen(y);i<strlen(x);i++)
	{
		memo[i][j]=strlen(x)-i;		
	}
	for (j=0,i=strlen(x);j<strlen(y);j++)
	{
		memo[i][j]=strlen(y)-j;		
	}
	printf("\t");
	for(j=0;j<strlen(x)+1;j++)
	printf("%c\t",y[j]);
	printf("\n\t");
	for (i=0;i<strlen(x)+1;i++)
	{	
		printf("\r%c\t",x[i]);
		for (j=0;j<strlen(y)+1;j++)
		{
		printf("%0.0f\t",memo[i][j]);
		}
		printf("\n\t");
	}
}
int edit_distance(char *x,char *y,int i,int j)
{	
	int coor_x=i,coor_y=j;
	int cost_delete,cost_insert,cost_replace,q=0;
	if (memo[i][j]<inf)
	return memo[i][j];
	printf("\r");
	for(coor_x=0;coor_x<strlen(x)+1;coor_x++)
	{
		for(coor_y=0;coor_y<strlen(y)+1;coor_y++)
		{
		cost_delete=edit_distance(x,y,i+1,j)+1;
		cost_insert=edit_distance(x,y,i,j+1)+1;
		cost_replace=edit_distance(x,y,i+1,j+1)+(x[i]==y[j]?0:2);
		q=min(cost_delete,cost_insert,cost_replace);
		if (memo[i][j]>q)
			memo[i][j]=q;
		}	
	}
	return memo[i][j];
}
int main()
{	
	int i,j=0;
	char x[]="kitten";
	char y[]="sitting";
	printf("string length of %s is %ld\n",x,strlen(x));
	printf("string length of %s is %ld\n",y,strlen(y));
	compute_base_cases(x,y);
	edit_distance(x,y,0,0);
	//printf("minimum %d\n",min(a,b,c));
	printf("\n");
	printf("\t");
	for(j=0;j<strlen(x)+1;j++)
	printf("%c\t",y[j]);
	printf("\n\t");
	for (i=0;i<strlen(x)+1;i++)
	{	
		printf("\r%c\t",x[i]);
		for (j=0;j<strlen(y)+1;j++)
		{
		printf("%0.0f\t",memo[i][j]);
		}
		printf("\n\t");
	}
	return 0;
}
