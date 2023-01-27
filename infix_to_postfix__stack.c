#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
} *top = NULL;

void push(char x)
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

char pop()
{
    struct node *t;
    char x = -1;
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
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
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

int isoperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '/' || x == '*')
        return 2;
    else
        return 0;
}

char *convert(char *infix)
{
    char *postfix = (char *)malloc(strlen(infix) + 1);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isoperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(stacktop()))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c/d-v";

    printf("%s ", convert(infix));

    return 0;
}