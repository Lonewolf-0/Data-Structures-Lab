#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*top1=NULL,*top2=NULL;

void push1(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Stack 1 is full");
    else
    {
        t->data = x;
        t->next = top1;
        top1 = t;
    }
}

void push2(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Stack 2 is full");
    else
    {
        t->data = x;
        t->next = top2;
        top2 = t;
    }
}

int pop1()
{
    int x = -1;
    struct node *p;
    if (top1 == NULL)
        printf("Stack 1 is empty\n");
    else
    {
        p = top1;
        top1 = top1->next;
        x = p->data;
        free(p);
    }
    return x;
}

int pop2()
{
    int x = -1;
    struct node *p;
    if (top2 == NULL)
        printf("Stack 2 is empty\n");
    else
    {
        p = top2;
        top2 = top2->next;
        x = p->data;
        free(p);
    }
    return x;
}

void enqueue(int x)
{
    push1(x);
}

int dequeue()
{
    int x=-1;
    if(top2==NULL)
    {
        while(top1!=NULL)
        {
            push2(pop1());
        }
    }
    return pop2();
}

void display_stack(struct node *p)
{
    
    if(p!=NULL)
    {
        display_stack(p->next);
        printf("%d ",p->data);
    }
}
void display()
{
    struct node *p = top2;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    display_stack(top1);
    printf("\n");
}


int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    display();

    return 0;
}