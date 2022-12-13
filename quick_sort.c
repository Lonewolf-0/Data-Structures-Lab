#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int l, int h,int a[])
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[l], &a[j]);
    // for (int i = 0; i < h; i++)
    //     printf("%d ", a[i]);
    // printf("\n");
    return j;
}
void quicksort(int l, int h,int a[])
{
    int j;
    if (l < h)
    {
        j = partition(l, h,a);
        quicksort(l, j,a);
        quicksort(j + 1, h,a);
    }
}
int main()
{
    int a[] = {50, 70, 60, 90, 40, 80, 10, 20, 30}, n = 9, i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    quicksort(0, n,a);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}