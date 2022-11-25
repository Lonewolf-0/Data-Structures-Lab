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
    int a[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    quicksort(0, n,a);
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}