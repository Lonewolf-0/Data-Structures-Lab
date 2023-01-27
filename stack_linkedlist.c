#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void push(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is empty");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display()
{
    struct node *p;
    p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int peek(int pos)
{
    int x = -1;
    struct node *p = top;
    while (--pos)
        p = p->next;
    x = p->data;
    return x;
}

int stacktop()
{
    if (top)
        return top->data;
    else
        return -1;
}

int isempty()
{
    return top ? 1 : 0;
}

int isfull()
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int r = t ? 1 : 0;
    free(t);
    return r;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    pop();
    display();

    return 0;
}