#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int a[20];
    int top;

}*s;


void create(struct stack *s1)
{
    s1->top=-1;
}

void push(struct stack *s1,int x)
{
    if(s1->top>20)
        printf("\nStack Overflow");
    else
    {
        s1->top++;
        s1->a[s1->top]=x;
    }
}
void conversion(struct stack *s1,int n)
{
    while(n!=0)
    {
        push(s1,n%16);
        n=n/16;
    }
}
void display(struct stack *s1)
{
    while(s1->top!=-1)
    {
        if(s1->a[s1->top]<=10)
        printf("%d ",s1->a[s1->top]);
        else
        printf("%c",(char)(54+s1->a[s1->top]));
        s1->top--;
    }

}


int main()
{
    int n=21;
    s=(struct stack*) malloc(sizeof(struct stack));
    create(s);
    conversion(s,n);
    display(s);



    return 0;
}