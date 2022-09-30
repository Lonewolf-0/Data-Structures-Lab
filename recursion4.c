#include<stdio.h>

int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}


int main()
{
   
    
    printf("%d ",gcd(6,21));
    


    return 0;
}
