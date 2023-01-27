#include <stdio.h>
#include <stdlib.h>

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

// int peek(int pos)
// {
//     int x = -1;
//     struct node *p = top;
//     while (--pos)
//         p = p->next;
//     x = p->data;
//     return x;
// }

// int stacktop()
// {
//     if (top)
//         return top->data;
//     else
//         return -1;
// }

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

int isbalanced(char *exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isBalanced(char *exp) // in this function expression can contain three types of brackets -> (), {}, [].
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == NULL)
                return 0;
            else if (top->data - exp[i] == -1 || top->data - exp[i] == -2) // ascii code of {} -> 40,41 ; [] -> 91,93 ; {} -> 123,125
                pop();
            else
                return 0;
        }
        display();
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "{[a+b]*(c-d)}";

    printf("%d ", isBalanced(exp));

    return 0;
}