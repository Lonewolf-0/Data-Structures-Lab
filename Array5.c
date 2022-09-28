#include<stdio.h>

int main()
{
    //missing number

    int arr[] = {1, 2, 4, 6, 3, 7, 8}, N = 8, sum1=0,sum2=0, missing;

    for(int i=0;i<N-1;i++)
    {
        sum1+=arr[i];
    }

    sum2=N*(N+1)/2;

    missing=sum2-sum1;


    printf("Missing element is : %d",missing);



}