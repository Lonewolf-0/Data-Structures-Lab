#include<stdio.h>
#include<stdlib.h>
#define size 8
struct node
{
    int data;
    struct node *next;
}*first;
void create(int a[],int n)
{
    struct node *t,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct node *p)
{
    if(p!=NULL)
        return 1+count(p->next);
    else
        return 0;
}

int sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int max(struct node *p)
{
    int max=p->data;
    while(p!=NULL)
    {
        if(max<p->data)
            max=p->data;
        p=p->next;
    }
    return max;
}
int main()
{
    int a[]={3,5,7,10,15,8,12,20};
    create(a,size);
    display(first);
    printf("\nNo. of Elements = %d",count(first));
    printf("\nSum = %d",sum(first));
    printf("\nMaximum Element = %d",max(first));



    return 0;
}
