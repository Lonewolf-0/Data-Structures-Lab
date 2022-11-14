#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct stack
{
    int a[20];
    int top;
}*s;

void create(struct stack *s1)
{
    s1->top=-1;
}

void push(struct stack *s1)
{
    if(s1->top>20)
        printf("\nStack Overflow");
    else
    {
        s1->top++;
        int x;
        printf("\nEnter element you want to push in stack - ");
        scanf("%d",&x);
        s1->a[s1->top]=x;
    }
}

void display(struct stack *s1)
{
    if(s1->top==-1)
        printf("\nStack is empty");
    else
    {   
        printf("\n");
        for(int i=0;i<=s1->top;i++)
        {
            printf("%d ",s1->a[i]);
        }
        getch();
    }
}
void top(struct stack *s1)
{
    if(s1->top==-1)
        printf("\nStack is empty");
    else
        printf("\nElement at top is %d",s1->a[s1->top]);
}

void pop(struct stack *s1)
{
    if(s1->top==-1)
        printf("\nStack Underflow");
    else
    {
        int x=s1->a[s1->top];
        s1->top--;
        printf("\nElement succesfully deleted - %d",x);
    }
}


int main()
{
    s=(struct stack*) malloc(sizeof(struct stack));
    create(s);
    
    
    int ch;
	while(1)
	{
       
		printf("\n1.push\n2.pop\n3.display\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push(s);
			    break;
			case 2:pop(s);
			    break;
			case 3:display(s);
			    break;
			case 4:exit(0);
			default:printf("invalid choice\n");
		}
	}





    return 0;
}