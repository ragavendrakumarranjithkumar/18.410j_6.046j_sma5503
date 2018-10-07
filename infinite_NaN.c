#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define m_inf -1.0/0.0
#define inf 1.0/0.0
int main()
{
	float array[10]={inf,inf,inf,inf,inf,inf,inf,inf,inf,inf};
	int i=0;
	float f=m_inf;
	printf("%f\n",f);
	printf("%d\n",(230984>m_inf));
	for(i=0;i<10;i++)
	printf("%f\t",array[i]);
	return 0;
}
