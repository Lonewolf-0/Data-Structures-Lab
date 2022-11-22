#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    char a[50];
    int top;
}*s;
char a[]="aryan";
char b[10];

void create(struct stack *s1)
{
    s1->top=-1;
}

void push(struct stack *s1)
{
    for(int i=0;a[i]!='\0';i++)
    {
        s1->top++;
        s1->a[s1->top]=a[i];
    }
}

int pop(struct stack *s1)
{
        int x=s1->a[s1->top];
        s1->top--;
        return x;
}

void reverse(struct stack *s1)
{
    int n=s1->top;
    for(int i=0;i<=n;i++)
    {
        b[i]=(char)pop(s);
    }
    printf("\n\n%s",b);
}
void check()
{
    int flag=0;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        {
            flag=1;
            break;
        }
    }
    if(flag)
        printf("\nNot a palindrome");
    else
        printf("\nPalindrome");
}

int main()
{
    s=(struct stack*)malloc(sizeof(struct stack));
    create(s);
    
    push(s);
    reverse(s);
    check();

    return 0;
}