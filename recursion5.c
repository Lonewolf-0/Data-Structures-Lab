
#include<stdio.h>
#include<math.h>
int binary_search(int a[],int key,int l,int h)
{   int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
    
        if(key<a[mid])
            return binary_search(a,key,l,mid-1);
        else
            if(key>a[mid])
                return binary_search(a,key,mid+1,h);
            else
                return mid;
    }
    return -1;

}

int main()
{
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int key=5,l=0,h=10;

    printf("\n1. Element found at %d ",binary_search(a,key,l,h));
}