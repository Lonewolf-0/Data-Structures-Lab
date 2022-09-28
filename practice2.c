#include<stdio.h>

int main()
{
    
    int a[]={1,3,5,6,8,9,12,30,29};
    int size=9;
    int max=a[0];
    int max2=a[0];
    
    for(int i=0;i<size;i++)
    {
        if(a[i]>max)
        {
            
            max=a[i];

        }

           
    }
    for(int i=0;i<size;i++)
    {
        if(a[i] > max2 && a[i] < max)
        max2=a[i];
    }
    

    printf("%d ",max);
    printf("%d ",max2);


    return 0;
}
