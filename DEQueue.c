#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void insert_from_front(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        t->next = front;
        front = t;
    }
}

void insert_from_rear(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Queue is full");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int delete_from_front()
{
    int x = -1;
    struct node *p;

    if (front == NULL)
        printf("Queue is Empty");
    else
    {
        x = front->data;
        p = front;
        front = front->next;
        free(p);
    }
}

int delete_from_rear()
{
    int x=-1;
    struct node *p;
    if(front==NULL)
        printf("Queue is empty");
    else
    {
        p=front;
        while(p->next!=rear)
            p=p->next;
        p->next=NULL;
        free(rear);
        rear=p;
    }
}

void display()
{
    struct node *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    insert_from_front(10);
    display();
    insert_from_front(20);
    display();
    insert_from_rear(30);
    display();
    delete_from_rear();
    display();
    delete_from_front();
    display();
    

    return 0;
}