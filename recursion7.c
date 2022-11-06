//Program to reverse the given number using Recursion
#include<stdio.h>
int sum=0;
int rem=0;
int reverse(int num)
{
    
   if(num){
    rem=num%10;
    sum=sum*10+rem;
    reverse(num/10);
  }
  else
    return sum;
  return sum;
}
int main()
{

    printf("%d",reverse(123));

    return 0;
}