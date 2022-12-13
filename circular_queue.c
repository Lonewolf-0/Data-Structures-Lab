#include<stdio.h>
#include<stdlib.h>
#define size 5
/****************************************************************/
struct queue
{
    int front,rear,a[size];
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
    if ((q.front == 0 && q.rear == size-1) ||
            (q.rear == (q.front-1)%(size-1)))
    {
        printf("\nQueue is Full");
        return;
    }
  
    else if (q.front == -1) 
    {
        q.front = q.rear = 0;
        q.a[q.rear] = x;
    }
  
    else if (q.rear == size-1 && q.front != 0)
    {
        q.rear = 0;
        q.a[q.rear] = x;
    }
  
    else
    {
        q.rear++;
        q.a[q.rear] = x;
    }
}
/****************************************************************/
int dequeue()
{
    if (q.front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }
  
    int data = q.a[q.front];
    q.a[q.front] = -1;
    if (q.front == q.rear)
    {
        q.front = -1;
        q.rear = -1;
    }
    else if (q.front == size-1)
        q.front = 0;
    else
        q.front++;
  
    return data;
}
/****************************************************************/
int main()
{   
    initialize();
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);

    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());

    enqueue(600);
    enqueue(700);
    enqueue(800);
    enqueue(900);

    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    printf("%d ",dequeue());
    





    return 0;
}