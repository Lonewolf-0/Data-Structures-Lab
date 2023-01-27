#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *t =(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Queue is full");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue()
{
    int x=-1;
    struct node *p;

    if(front==NULL)
        printf("Queue is Empty");
    else
    {
        x=front->data;
        p=front;
        front=front->next;
        free(p);
    }
}

void display()
{
    struct node *p=front;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();

    return 0;
}