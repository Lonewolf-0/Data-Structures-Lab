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


struct node* delete()
{
    struct node* temp= first;
    first=first->next;
    return temp;
}

struct node* delete_any_position(struct node* p,int index)
{
    struct node* q=NULL;
    int c=0;
    while (p!=NULL)
    {
        if(index==c)
        {
            struct node* temp=p;
            q->next=p->next;
            return temp;
        }
        q=p;
        p=p->next;
        
        c++;
    }
    return NULL;
}




int main()
{
    int a[]={5,1,2,3,5,5,4,5,3,5};
    create(a,size);
    display(first);
    


    return 0;
}