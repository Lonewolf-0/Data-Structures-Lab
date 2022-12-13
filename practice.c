#include<stdio.h>
#include<stdlib.h>
#define size 5

struct node
{
    int data;
    struct node *next;
}*first;

void create(int a[],int n)
{
    struct node *t,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
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
    int c=0;
    while (p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c; 
}

struct node* search(struct node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}



int main()
{
    int a[]={1,4,7,9,15};
    create(a,size);
    display(first);
    printf("\nNo. of elements : %d ",count(first));

    struct node* temp=search(first,1);
    printf("\nElement found at address : %d ",temp);
    
    



    return 0;
}