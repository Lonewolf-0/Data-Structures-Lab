#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
} *first = NULL;

void create(int a[], int n)
{
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(struct node *p, int index, int x)
{
    struct node *t;
    if(index<0||index>length(p))
        return;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if(index==0)
    {
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        if(p->next)p->next->prev=t;
        p->next=t;
    }
}

int delete(struct node *p, int index)
{
    struct node *q;
    int x=-1;
    if(index<1||index>length(p))
        return -1;
    if(index==1)
    {
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void reverse(struct node *p)
{
    struct node *temp;
    while(p)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL&& p->next==NULL)
            first=p;
    }
}



int main()
{
    int a[] = {1, 2, 5, 7, 9};
    create(a, 5);
    display(first);
    printf("%d\n", length(first));
    insert(first,2,3);
    display(first);
    reverse(first);
    display(first);
    return 0;
}
