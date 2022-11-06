//To check if the given string is a palindrome using Recursion

#include<stdio.h>

int check(int n)
{
    int sum=0;
    int reverse(int num)
    {
        
        if(num)
        {
            
            sum=sum*10+num%10;
            reverse(num/10);
        }
        else
            return sum;
        return sum;
    }

    if(reverse(n)==n)
        printf("Palindrome");
    else
        printf("Not a palindrome");

}

int main()
{

    check(121);

    return 0;
}