#include<stdio.h>

struct complex 
{
    int real,imaginary;
};

int main()
{
    //8. Write a program to add, subtract and multiply two complex numbers using structures to function.
    struct complex a,b,sum,difference,product;
    printf("\nEnter real and imaginary values of complex number 1 : ");
    scanf("%d%d",&a.real,&a.imaginary);
    printf("\nEnter real and imaginary values of complex number 2 : ");
    scanf("%d%d",&b.real,&b.imaginary);

    sum.real=a.real+b.real;
    sum.imaginary=a.imaginary+b.imaginary;

    difference.real=a.real-b.real;
    difference.imaginary=a.imaginary-b.imaginary;

    product.real=a.real*b.real-a.imaginary*b.imaginary;
    product.imaginary=a.imaginary*b.real+b.imaginary*a.real;

    printf("\n Sum : (%d) + i(%d) ",sum.real,sum.imaginary);
    printf("\n Difference : (%d) + i(%d) ",difference.real,difference.imaginary);
    printf("\n Product : (%d) + i(%d) ",product.real,product.imaginary);

    


    return 0;
}