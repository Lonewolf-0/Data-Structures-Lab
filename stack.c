// implementation using array
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st, int size)
{
    // printf("\nEnter size ");
    // scanf("%d",&st->size);
    st->size = size;
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct stack st)
{
    st.top++;
    while ((st.top)--)
        printf("%d ", st.s[st.top]);
    printf("\n");
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow \n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack *st)
{
    int x;
    if (st->top == -1)
        printf("Stack Underflow \n");
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int peek(struct stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid index \n");
    x = st.s[st.top - index + 1];

    return x;
}

int isempty(struct stack st)
{
    return st.top == -1;
}

int isfull(struct stack st)
{
    return st.top == st.size - 1;
}

int stacktop(struct stack st)
{
    if (!isempty(st))
        return st.s[st.top];
    return -1;
}

int main()
{
    struct stack st;
    create(&st, 7);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    display(st);
    pop(&st);
    display(st);
    printf("\n%d ", peek(st, 4));
}