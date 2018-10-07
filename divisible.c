#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	assert(b!=0);
	printf("%d/%d=%0.2f ",a,b,a/(float)b);
	return 0;
}
