#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
void inorder(struct node* root){
 if(root == NULL) return;
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
}
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

struct node* search(struct node *root,int searchdata)
{
    struct node *current = root;

 while(current->data != searchdata)
{
 if (current != NULL) {
   printf("%d ",current->data);

    if(current->data > searchdata){ //go to left tree
      current = current->left;}

      else { //go to right tree
 current = current->right;
 }
 //not found
 if(current == NULL){
 return NULL;
 } }
 }
 return current;
    
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;
 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
            if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
           }
            else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
           }
            struct node* current = root->right;
        while (current && current->left != NULL)
        current = current->left;
        root->data = current->data;
         root->right = deleteNode(root->right, current->data);
    }
    return root;
}

void main(){
    struct node *root = NULL;
    int ch = 0, item,i = 1,n;
    struct node *pos =NULL;
    printf("Binary Search Tree Creation");
   /* printf("\nEnter the no of nodes:");
    scanf("%d",&n);
    while(i<=n){
        printf("Item:");
        scanf("%d", &item);
            root = enternode(root, item);
            i++;
    }*/
    while (ch>=1 || ch<=3)
    {
        printf("\n1)insertion");  
        printf("\n2)deletion");
        printf("\n3)search");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: printf("insertion:");
                 printf("Item:");
                 scanf("%d", &item);
                 root = enternode(root, item);
                 printf("display:");
                 inorder(root);
                break;
        case 2:printf("deletion : \t");
               printf(" which element to be deleted:\n");
               scanf("%d",&item);
               root = deleteNode(root, item);
                printf("display:");
                 inorder(root);
                break;
        case 3:printf("search:  \t");
                 printf("display:");
                 inorder(root);
                printf(" which element to be searched:\n");
               scanf("%d",&item);
               pos =search(root, item);
               if(pos != NULL)
						printf("\nThe element %d was found in the binary search tree\n", item);
					else
						printf("\nThe element %d was not found in the binary search tree\n", item);
                break;
        case 4:exit(0);
        }}
    }
