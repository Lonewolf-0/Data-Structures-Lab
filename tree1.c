#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "stack.h"
struct node *root = NULL;
void treecreate()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);
    printf("Eneter root value ");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    while (!isempty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if (p)
    {
        preorder(p->lchild);
        printf("%d ", p->data);
        preorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if (p)
    {
        preorder(p->lchild);
        preorder(p->rchild);
        printf("%d ", p->data);
    }
}
void ipreorder(struct node *p)
{
    struct stack stk;
    stackcreate(&stk, 100);

    while (p || isemptystack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void levelorder(struct node *p)
{
    struct queue q;
    create(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while(!isempty(q))
    {
        p=dequeue(&q);
        
        if(p->lchild)
        {
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild)
        {
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}

int count(struct node *p)
{
    int x,y;
    if(p)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}


int main()
{
    treecreate();
    levelorder(root);


    return 0;
}