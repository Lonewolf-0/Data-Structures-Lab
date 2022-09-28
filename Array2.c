#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Program to insert the given elements into an array.

    
    int a[]={3,5,6,3,6,2,7,5,8,4,0};
    int size = 11, x, index;
    int temp;

    printf("Enter index where you want to insert element ");
    scanf("%d,&index");
    printf("Enter element to be inserted ");
    scanf("%d",&x);

    
    for(int i=size-1 ;i>=index ;i--)
    {
        a[i]=a[i-1];
    }
    a[index]=x;

    //print

    for (int i = 0; i < size ; i++)
    {
        printf("%d ",a[i]);
    }
    

    return 0;
}
