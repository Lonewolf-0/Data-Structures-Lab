#include<stdio.h>


int power(int a,int b)
{
    if(b==1)
        return a;
    else
        return a*power(a,b-1);
}
int main()
{
    printf("%d ",power(5,2));
}