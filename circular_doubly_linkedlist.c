#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next, *prev;
    int data;
} *head = NULL;

void create(int a[], int n)
{
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    head->prev = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->prev = last;
        last->next = t;
        t->next = head;
        head->prev = t;
        last = t;
    }
}

void display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void insert(struct node *p, int index, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data=x;
    if (index == 0)
    {
        while(p->next!=head)p=p->next;
        p->next=t;
        t->prev=p;
        t->next=head;
        head->prev=t;
        head=t;
    }
    else
    {
        while(--index)p=p->next;
        t->next=p->next;
        p->next->prev=t;
        p->next=t;
        t->prev=p;
    }
}

int delete(struct node *p, int index)
{
    int x;
    if(index==0)
    {
        x=head->data;
        while (p->next != head)
            p = p->next;
        head=head->next;
        if(head)head->prev=p;
        p->next=head;
    }
    else
    {
        while(index--)p=p->next;
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
    }
}
int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    display(head);
    insert(head,2,25);
    display(head);
    delete(head,2);
    display(head);

    return 0;
}
