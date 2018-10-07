#include<stdio.h>
#include<stdlib.h>
/*****************************************************************
array name is tself  a  pointer  therefore to access the value of 
the first element  stored in the array use *(a) or a[0] or *(a+0)
for second element use *(a+1) or a[1]
for third element use *(a+2) or a[2]
and so on...
here we use an array of pointers 
*****************************************************************/
int main()
{
int i=0;
int *a[5];
// allocates memery to all(array) pointers
for(i=0;i<5;i++)
*(a+i)=(int*) malloc(sizeof(int));
/*
for(i=0;i<5;i++)
a[i]=(int*) malloc(sizeof(int));
//*(a)=(int*) malloc(sizeof(int));
//*(a+1)=(int*) malloc(sizeof(int));
is also a equally valid stmt
a[i] is also a pointer here
note:  both *(a+i) and a[i]  are pointers 
and can be used as an lvalue in malloc.
*/
**(a)=10;
**(a+1)=20;
**(a+2)=60;
*a[3]=50;
/*
the resaon for using two astreiks(**) here is that
*(a+i) or a[i] is just a pointer to an integer, to change the value 
at that integer we use another *
*/
int temp;
/*
these stmts are rarely used because here declaring an
int temp itself allocates memeory we are just using 
temp_ptr to point to that address 
*/
int *temp_ptr=&temp;
*temp_ptr=90;
printf("%d\n",*a[0]);
printf("%d\n",*a[1]);
printf("%d\n",*a[2]);
printf("%d\n",*a[3]);
printf("%d\n",*temp_ptr);
printf("%d\n",temp);
temp=70;
printf("%d\n",*temp_ptr);
printf("%d\n",temp);
return 0;
}

