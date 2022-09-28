#include<stdio.h>

int main()
{
    int n,a[50];
    printf("Enter no of elements in an array : ");
    scanf("%d",&n);
    printf("Enter element : ");
    for(int i=0;i<n;i++)
    {   
        scanf("%d",&a[i]);

    }

    for(int i=0;i<n/2;i++)
    {
        int temp;
        temp=a[n-1-i];
        a[n-i]=a[i];
        a[i]=temp;
    }

    printf("reversed array = \n");

     for (int i = 0; i < 10 ; i++)
    {
        printf("%d ",a[i]);
    }
    

    return 0;
}