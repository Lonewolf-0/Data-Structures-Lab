#include <stdio.h>

void merged_array(int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
        // else
        // {
        //     c[k] = a[i];
        //     i++;
        //     j++;
        //     k++;
        // }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    // print

    printf("Merged Array : ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void union_array (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (b[j] < a[i])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else
        {   c[k]=a[i];
            i++;
            j++;
            k++;  
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    // print

    printf("Union : ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void intersection (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            
            j++;
            
        }
        else
        {   c[k]=a[i];
            i++;
            j++;
            k++;  
        }
    }

    

    // print

    printf("Intersection : ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void difference (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (b[j] < a[i])
        {
            
            j++;
            
        }
        else
        {   
            i++;
            j++;
             
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    

    // print

    printf("Difference : ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void symmentric_difference (int a[], int m, int n, int b[])
{
    int i, j, k;
    int c[20];
    i = 0;
    j = 0;
    k = 0;

    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else if (b[j] < a[i])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else
        {   
            i++;
            j++;
            
        }
    }

    while (i < m)
    {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n)
    {
        c[k] = b[j];
        k++;
        j++;
    }

    // print

    printf("Symmetric Difference : ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
int main()
{
    // program for union of two sets
    int a[] = {1, 3, 4, 5, 9}, b[] = {3, 4, 5, 6, 7, 8, 9, 10}, m = 5, n = 8;

    printf("\nArray 1 : \n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nArray 2 : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");

    merged_array(a, m, n, b);
    union_array(a,m,n,b);
    intersection(a, m, n, b);
    difference(a,m,n,b);
    symmentric_difference(a,m,n,b);

    return 0;
}