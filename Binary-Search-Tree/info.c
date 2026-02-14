/*b) Write a C program to maintain a phonebook using Binary Search Tree by name where each node contain
contact name and phone number.*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    struct node* left;
    char name[100];
    int pno;
    struct node* right;
};

struct node* createNode(struct node* root , char name[] , int pno){
    if(root == NULL){
        root = malloc(sizeof(struct node));
        strcpy(root->name,name);
        root->pno = pno;
        root->left = root->right = NULL;
        return root;
    }
    if(strcmp(name,root->name)<0){
        root->left = createNode(root->left, name, pno);
    }
    else if(strcmp(name,root->name)>0){
        root->right = createNode(root->right, name, pno);
    }
    else{
        printf("\nDuplicate Data is NOT ALLOWED\n");
    }
    return root;
    
}
void print(struct node* root){
    if(root==NULL){
        return;
    }
    print(root->left);
    printf("Name - %s\n",root->name);
    printf("Mobile No. - %d\n\n",root->pno);
    print(root->right);
}

int main() {
    int n , i , pno;
    char name[100];
    struct node* root = NULL;
    printf("Enter How many Elements you want to add in TREE ");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++){
        printf("Enter Name - ",i);
        scanf("%s",name);
        printf("Enter Mobile NO. - ");
        scanf("%d",&pno);
        root = createNode(root, name, pno);
    }
    print(root);
    return 0;
}