#include<stdio.h>

int a[]={3,5,2,7,4,9,1};
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int l,int h)
{
    int pivot=a[l];
    int i=l-1,j=h;
    while(i<j)
    {
        while(a[i]<=pivot)i++;
        while(a[i]>pivot)j--;
        if(i<j)swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}
void quicksort(int l,int h)
{
    if(l<h)
    {
        int j=partition(l,h);
        quicksort(l,j);
        quicksort(j+1,h);
    }
}
int main()
{
    for(int i=0;i<7;i++)printf("%d ",a[i]);
    printf("\n");
    quicksort(0,7);
    for(int i=0;i<7;i++)printf("%d ",a[i]);


    return 0;
}