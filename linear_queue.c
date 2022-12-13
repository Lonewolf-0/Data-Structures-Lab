#include<stdio.h>
#include<stdlib.h>
/****************************************************************/
struct queue
{
    int front,rear,a[20];
}q;
/****************************************************************/
void initialize()
{
    q.front=q.rear=-1;
}
/****************************************************************/
int is_empty()
{
    if(q.rear==q.front)
        return 1;
    else
        return 0;
}
/****************************************************************/
void enqueue(int x)
{
    if(q.rear>=19)
        printf("\nOverflow");
    else
    {
        q.rear++;
        q.a[q.rear]=x;
    }
}
/****************************************************************/
int dequeue()
{
    if(is_empty())
    {
        printf("\nUnderflow");
        return 0;
    }
    else
    {
        q.front++;
        int x = q.a[q.front];
        return x;
    }
}
/****************************************************************/
int main()
{   
    initialize();
    enqueue(100);
    enqueue(200);
    enqueue(300);
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    





    return 0;
}