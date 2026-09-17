/* a) Write a C program which uses Binary search tree library and implements following function with recursion:
int copy(T) – create another BST which is exact copy of BST which is passed as parameter.
int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal and 0
otherwise.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNode(struct node* root , int data){
    if(root == NULL){
        root = malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data){
        root->left = createNode(root->left , data);
    }
    else if(data > root->data){
        root->right = createNode(root->right , data);
    }
    else{
        printf("\n\nDuplicates Not Allowed");
    }
    return root;
}

struct node* coppyTree(struct node *root){
    if(root == NULL){
        return NULL;
    }
    struct node* root2 = malloc(sizeof(struct node));
    root2->data = root->data;
    root2->left = coppyTree(root->left); 
    root2->right = coppyTree(root->right);
    return root2;
}
void print(struct node* root){
    if(root == NULL){
        return;
    }
    print(root->left);
    printf("-%d-",root->data);
    print(root->right);
}

int isIdentical(struct node* root1 , struct node* root2){
    if(root1 == NULL && root2 == NULL){
        return 1;
    }
    
    if(root1 == NULL || root2 == NULL){
        return 0;    
    }
    
    if(root1->data == root2->data){
       return isIdentical(root1->left , root2->left) && isIdentical(root1->right , root2->right);
    }
    
    else{
    return 0;
    }
}
int oddSum(struct node* root){
    if(root == NULL){
        return 0;
    }
    return (root->data % 2 != 0 ? root->data : 0) + oddSum(root->left) + oddSum(root->right);
}
int evenSum(struct node* root){
    if(root == NULL){
        return 0;
    }
    return (root->data % 2 == 0 ? root->data : 0) + evenSum(root->left) + evenSum(root->right);
}

struct node* mirrorImage(struct node* root){
    if(root==NULL){
        return NULL;
    }
    struct node* root3 = malloc(sizeof(struct node));
    
    root3->data = root->data;
    root3->left = mirrorImage(root->right);
    root3->right = mirrorImage(root->left);
    
    return root3;
}
struct node* leftMost(struct node* root){
    return leftMost(root->left);
}
int main(){
    int n , i , data;
    struct node* root = NULL;
    printf("Enter How Many Elements You Want to Add in Tree ");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++){
        printf("\nEnter Data %d - ",i);
        scanf("%d",&data);
        root = createNode(root,data);
    }
    printf("\n\n");
    printf("Binary Search Tree =  ");
    print(root);
    struct node* root2 = coppyTree(root);
    printf("\n\nCoppied Binary Search Tree =  ");
    print(root2);
    if(isIdentical(root , root2)){
        printf("\n\nBoth The Trees are SAME");
    }
    else{
        printf("\n\nTrees are NOT SAME");
    }
    printf("\n\nSum of Odd Numbers is %d",oddSum(root));
    printf("\n\nSum of Even Numbers is %d\n\n",evenSum(root));
    
    struct node* root3 = mirrorImage(root);
    print(root3);
    
}