#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *enternode(struct node *root, int k)
{
    if (root == NULL){
        struct node*newnode;
        newnode = malloc(sizeof(struct node));
        newnode->data = k;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (k < root->data)
        root->left = enternode(root->left, k);
    else
        root->right = enternode(root->right, k);
    return root;
}
//DLR preorder traversal
struct node *Preorder(struct node *root)
{
    if (root == NULL)
        return root;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
    
}

// LRD postorder traversal
struct node *Postorder(struct node *root)
{
    if (root == NULL)
        return root;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
    
}

//LDR inorder traversal
struct node *Inorder(struct node *root)
{
    if (root == NULL)
        return root;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
    
}
void main(){
    struct node *root = NULL;
    int ch = 0, item,i = 1,n;
    printf("\nBinary Search Tree Creation");
    printf("\nEnter the no of nodes:");
    scanf("%d",&n);
    while(i<=n){
        printf("Item:");
        scanf("%d", &item);
            root = enternode(root, item);
            i++;
    }
    while (ch>=1 || ch<=3)
    {
        printf("\n1)Inorder Traversal");  
        printf("\n2)Preorder Traversal");
        printf("\n3)Postorder Traversal");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: printf("\nInorder traversal:");
                Inorder(root);
                printf("\n");
                break;
        case 2:printf("\nPreorder traversal:");
               Preorder(root);
               printf("\n");
                break;
        case 3:printf("\nPostorder traversal:");
               Postorder(root);
               printf("\n");
                break;
        case 4:exit(0);
        }
    }
}