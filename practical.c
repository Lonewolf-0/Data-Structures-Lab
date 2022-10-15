#include<stdio.h>

void tower_of_hanoi(int n,char a,char b,char c)
{
    if(n>0)
    {
        tower_of_hanoi(n-1,a,c,b);
        printf("\nMove disk %d from %c to %c ",n,a,c);
        tower_of_hanoi(n-1,b,a,c);
    }
}

int main()
{
    tower_of_hanoi(3,'A','B','C');

    return 0;
}