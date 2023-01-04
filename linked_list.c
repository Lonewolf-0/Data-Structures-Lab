#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define size 8

struct node
{
    int data;
    struct node *next;
} *first, *last, *second;

void create(int a[], int n)
{
    struct node *t;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int b[], int n)
{
    struct node *t;
    struct node *last;

    second = (struct node *)malloc(sizeof(struct node));
    second->data = b[0];
    second->next = NULL;
    last = second;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = b[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    printf("\nList :");
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
}

int count(struct node *p)
{
    if (p != NULL)
        return 1 + count(p->next);
    else
        return 0;
}

int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int max(struct node *p)
{
    int max = p->data;
    while (p != NULL)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

void insert_before_first(struct node *p, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = first;
    first = t;
}

void insert_at_position(struct node *p, int x, int pos)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    int c = 0;
    while (p != NULL)
    {

        if (c == pos)
        {
            t->next = p->next;
            p->next = t;
        }
        c++;
        p = p->next;
    }
}

void insert_at_last(struct node *p, int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    last->next = t;
    last = t;
}

void delete_beg(struct node *p)
{
    first = first->next;
    free(p);
}

void delete_at_position(struct node *p, int pos)
{
    struct node *q = NULL;
    int c = 1;
    while (c < pos)
    {
        c++;
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
}

bool isSorted(struct node *p)
{
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}

void remove_duplicates(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverse(struct node *p)
{
    struct node *q = NULL;
    struct node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse_using_recursion(struct node *q, struct node *p)
{
    if (p != NULL)
    {
        reverse_using_recursion(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

// struct node *merge(struct node *p, struct node *q)
// {
//     struct node *third = NULL;
//     while (p != NULL && q != NULL)
//     {
//         if (p->data < q->data)
//         {
//             insert_before_first(third, p->data);
//             p = p->next;
//         }
//         else
//         {
//             insert_before_first(third, q->data);
//             q = q->next;
//         }
//     }
//     while (p != NULL)
//     {
//         insert_before_first(third, p->data);
//         p = p->next;
//     }
//     while (q != NULL)
//     {
//         insert_before_first(third, q->data);
//         q = q->next;
//     }
//     reverse(third);
//     return third;
// }

// struct node *set_union(struct node *p, struct node *q)
// {
//     struct node *third = NULL;
//     while (p != NULL && q != NULL)
//     {
//         if (p->data < q->data)
//         {
//             insert_before_first(third, p->data);
//             p = p->next;
//         }
//         else
//         {
//             if (p->data > q->data)
//             {
//                 insert_before_first(third, q->data);
//                 q = q->next;
//             }
//             else
//             {
//                 insert_before_first(third, q->data);
//                 q = q->next;
//                 p = p->next;
//             }
//         }
//     }
//     while (p != NULL)
//     {
//         insert_before_first(third, p->data);
//         p = p->next;
//     }
//     while (q != NULL)
//     {
//         insert_before_first(third, q->data);
//         q = q->next;
//     }
//     reverse(third);
//     return third;
// }

// struct node *intersection(struct node *p, struct node *q)
// {
//     struct node *third = NULL;
//     while (p != NULL && q != NULL)
//     {
//         if (p->data < q->data)
//         {
//             p = p->next;
//         }
//         else
//         {
//             if (p->data > q->data)
//             {
//                 q = q->next;
//             }
//             else
//             {
//                 insert_before_first(third, q->data);
//                 q = q->next;
//                 p = p->next;
//             }
//         }
//     }
//     reverse(third);
//     return third;
// }

// struct node *difference(struct node *p, struct node *q)
// {
//     struct node *third = NULL;
//     while (p != NULL && q != NULL)
//     {
//         if (p->data < q->data)
//         {
//             insert_before_first(third, p->data);
//             p = p->next;
//         }
//         else
//         {
//             if (p->data > q->data)
//             {
//                 q = q->next;
//             }
//             else
//             {
//                 insert_before_first(third, q->data);
//                 q = q->next;
//                 p = p->next;
//             }
//         }
//     }
//     while (p != NULL)
//     {
//         insert_before_first(third, p->data);
//         p = p->next;
//     }
//     reverse(third);
//     return third;
// }

// struct node *symmetric_difference(struct node *p, struct node *q)
// {
//     struct node *third = NULL;
//     while (p != NULL && q != NULL)
//     {
//         if (p->data < q->data)
//         {
//             insert_before_first(third, p->data);
//             p = p->next;
//         }
//         else
//         {
//             if (p->data > q->data)
//             {
//                 insert_before_first(third, q->data);
//                 q = q->next;
//             }
//             else
//             {
//                 q = q->next;
//                 p = p->next;
//             }
//         }
//     }
//     while (p != NULL)
//     {
//         insert_before_first(third, p->data);
//         p = p->next;
//     }
//     while (q != NULL)
//     {
//         insert_before_first(third, q->data);
//         q = q->next;
//     }
//     reverse(third);
//     return third;
// }

int main()
{
    int a[] = {3, 5, 7, 10, 15, 18, 20, 20};
    int b[] = {1, 2, 4, 5, 6, 10};
    create(a, size);
    display(first);
    create2(b, 6);
    display(second);


    // printf("\nNo. of Elements = %d", count(first));

    // printf("\nSum = %d", sum(first));

    // printf("\nMaximum Element = %d", max(first));

    // insert_before_first(first, 4);
    // display(first);

    // insert_at_position(first, 9, 3);
    // display(first);

    // insert_at_last(first, 30);
    // display(first);

    // delete_beg(first);
    // display(first);

    // delete_at_position(first, 3);
    // display(first);

    // if (isSorted(first))
    //     printf("\nList is sorted ");
    // else
    //     printf("\nList is not sorted ");

    // remove_duplicates(first);
    // display(first);

    // reverse(first);
    // display(first);

    printf("\nMerge : ");
    display(merge(first, second));

    printf("\nUnion : ");
    display(set_union(first, second));

    printf("\nIntersection : ");
    display(intersection(first, second));

    printf("\nDifference : ");
    display(difference(first, second));

    printf("\nSymmetric Difference : ");
    display(symmetric_difference(first, second));

    

    return 0;
}
