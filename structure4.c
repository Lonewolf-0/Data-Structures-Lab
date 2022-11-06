#include<stdio.h>

/*4. Write a program to add two distances in inch-feet using structure. 
The values of the distances is to be taken from the user.*/

struct distance
{
    int feet,inch;   

};

int main()
{
    struct distance a,b,c;
    
    printf("\nEnter distance 1 in feet and inches : ");
    scanf("%d%d",&a.feet,&a.inch);
    printf("\nEnter distance 2 in feet and inches : ");
    scanf("%d%d",&b.feet,&b.inch);

    c.feet=a.feet+b.feet+(a.inch+b.inch)/12;
    c.inch=(a.inch+b.inch)%12;
    printf("\nSum of distances is : %d foot and %d inches ",c.feet,c.inch);


    
    

    return 0;
}
