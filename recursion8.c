#include <stdio.h> 
int sum(int n)
{
    if(n/10==0)
        return n;
    else
        return n%10+sum(n/10);
}

int main() 
{   
    int n=1020;
    printf("%d",sum(n));
    return 0;
}