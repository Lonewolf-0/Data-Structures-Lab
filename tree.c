#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *l;
    struct node *r;
};
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    else
        inorder(root->l);
    printf("%d\n", root->data);
    inorder(root->r);
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->data);
    preorder(root->l);
    preorder(root->r);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;

    preorder(root->l);
    preorder(root->r);
    printf("%d\n", root->data);
}
int height(struct node *root)
{
    int l,r;
    if (root == NULL)
        return 0;
    else
    {
        l = height(root->l);
        r = height(root->r);
        if (l > r)
        {
            return l + 1;
        }
        else
            return r + 1;
    }
}
int size(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return (1+size(root->l)+size(root->r));
}
int sum(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return root->data+sum(root->l)+sum(root->r);
}
int countone(struct node *root)
{
    if (root==NULL)
        return 0;
    else
    {
        if(root->l!=NULL&&root->r==NULL)
            return countone(root->l)+1;
        else
            if(root->l==NULL && root->r!=NULL)
                return countone(root->r)+1;
        return countone(root->l)+countone(root->r);
    }
}

struct node *newnode(int data)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->l = NULL;
    root->r = NULL;
    return root;
}
int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root = newnode(1);
    root->l = newnode(2);
    root->r = newnode(3);
    root->l->l = newnode(4);
    root->l->r = newnode(5);
    root->l->l->l = newnode(6);
    root->l->l->r = newnode(7);
    printf("Inorder:\n");
    inorder(root);

    printf("\npreorder:\n");
    preorder(root);

    printf("\npostorder:\n");
    postorder(root);

    printf("\nheight : %d", height(root));

    printf("\nsize : %d", size(root));

    printf("\nsum : %d", sum(root));

    printf("\ncountone : %d", countone(root));

    

}