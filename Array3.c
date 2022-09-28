#include<stdio.h>

int main(int argc, char const *argv[])
{
    //Program for insetion in the sorted array

    int a[]={1,12,15,18,36,45,67,77,78,89,0};
    int x,size=11,index;

    printf("Enter element to be inserted ");
    scanf("%d",&x);

    for(int i=0;i<size-1;i++)
    {
        if(x > a[i])
        {   
            index=i-1;
            break;
            
        
        }
    }

    printf("index=%d",index);
   
    return 0;
}
