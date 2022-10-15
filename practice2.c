#include<stdio.h>

void oned_address(int a[],int size)
{
    int i=3,add;
    printf("\nBase Address : %d",a);
    add=&a[0]+(i)*sizeof(int);
    printf("  %lu",sizeof(int));
    printf("\nAddress : %d",&a[3]);
    printf("\nCalculated : %d",add);

}

int main()
{   

    int a[]={1,3,4,5,7,8,9};
    int size=7;
    oned_address(a,size);

    return 0;
}