// Program to find which element is repeated in the array and which is not

#include <stdio.h>

int main()
{
    int a[100], flag[100], n;

    printf("Enter no of elements in an array : ");
    scanf("%d", &n);
    printf("Enter element : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
                sum = sum + 1;
        }
        if (sum > 1)
            flag[i] = 1;
        else
            flag[i] = 0;
    }

    //printing

    //repeating element

    printf("Repeated elements are : ");
    for(int i=0;i<n;i++)
    {
        if(flag[i]==1)
        printf("%d ",a[i]);
    }
    printf("Non Repeated elements are : ");
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0)
        printf("%d ",a[i]);
    }
    return 0;
}