#include<stdio.h>
int sum;
int sum_of_digits(int n)
{
    if (n < 10) 
    {
        return n;
    }
    else 
    {
        return n%10 + sum_of_digits(n/10);
    }
    
    
        
}




int main()
{
    //sum of digits
    printf("%d ",sum_of_digits(1340));

}