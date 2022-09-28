#include <stdio.h>
void bubble_sort(int a[], int size)
{
    int flag = 1;

    for (int i = 0; i < size - 1 && flag == 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
    }

    printf("\nSorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
}

void counting_sort(int a[], int size)
{
    int c[100] = {0}, b[100] = {0};
    int max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    for (int i = 1; i <= size; i++)
    {
        c[a[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        b[i] = c[i] + c[i - 1];
    }
    for (int j = size - 1; j >= 0; j--)
    {
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
    printf("\nSorted Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", c[i]);
}
int main()
{
    int a[] = {3, 6, 8, 3, 2, 8, 9, 5, 4, 3}, size = 10;
    counting_sort(a, size);
    bubble_sort(a, size);

    return 0;
}