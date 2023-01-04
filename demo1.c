#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *createdoublyll(struct node *head)
{
    struct node *newnode, *ptr;
    int num;
    printf("enter -1 to end\n");
    printf("enter the data\n");
    scanf("%d", &num);
    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (head == NULL)
        {
            newnode->prev = NULL;
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = NULL;
        }
        tail = ptr->next;
        printf("enter the data\n");
        scanf("%d", &num);
    }
    return head;
}
struct node *displayhead(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}
struct node *displaytail(struct node *tail)
{
    struct node *ptr;
    ptr = tail;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
    return tail;
}
int main()
{
    int option;
    do
    {
        printf("***********\n");
        printf("1. Create a link list\n");
        printf("2. Display the link list from head\n");
        printf("3. Display the link list from tail\n");
        printf("4. EXIT\n");
        printf("enter your choice\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = createdoublyll(head);
            break;
        case 2:
            head = displayhead(head);
            break;
        case 3:
            tail = displaytail(tail);
            break;
        }
    } while (option != 4);

    return 0;
}