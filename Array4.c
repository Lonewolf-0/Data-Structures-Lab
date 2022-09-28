#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Program for delete the given elements into an array.

    int a[]={3,2,6,4,7,5,7,9,4,5};
    int size=10;

    int index=5;
    


    printf("Enter index of element to be deleted (less than %d ) ",size);
    scanf("%d",&index);
    int deleted_element=a[index];
    for(int i=index;i<size-1;i++)
    {
        a[i]=a[i+1];
    }

    //print
    printf("Array after deletion : ");
    for (int i = 0; i < size-1; i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\nDeleted Element: %d",deleted_element);

    return 0;
}
