#include<stdio.h>

int dat[101];

int fib(int n)
{
    if(n==1)
        dat[n]=0;
    else
        if(dat[n]==0)
            dat[n]=fib(n-1)+fib(n-2);

    return dat[n];
}
int main()
{
   
    
    
    int i;
    for( i=0;i<100;i++)
    {
        printf("%d .) %d \n",i,fib(i));

    }
    // int x=0;
    // int y=1;
    
    // for(i=1;i<=100;i++)
    // {
        
    //     int sum=x+y;
    //     printf("%d .) %d \n",i,sum);
    //     y=x;
    //     x=sum;
    // }


    return 0;
}
