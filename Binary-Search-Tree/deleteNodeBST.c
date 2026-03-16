#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

// Function to find the leftmost node (in-order successor) in a given subtree
struct node* leftMost(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to print the binary search tree (in-order traversal used here)
void print(struct node* root) {
    if (root != NULL) {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

struct node* createNode(struct node* root , int data){
    if(root == NULL){
        root = malloc(sizeof (struct node));
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
        printf("Duplicate Keys are Not Allowed\n");
    }
    return root;
}

struct node* deleteNode(struct node* root , int del){
    if(root == NULL){
        printf("Root is Not Present");
        return NULL;
    }
    if(del < root->data){
        root->left = deleteNode(root->left , del);
    }
    else if(del > root->data){
        root->right = deleteNode(root->right , del);
    }
    else{
        //Root Having No Child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //Root Having Right Child
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        //Root Having Left Child
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        //Root Having Both Childs
        else{
        struct node* temp = leftMost(root->right);
        temp->left = root->left;
        temp->right = root->right;
        free(root);
        return temp;
        }
    }
    return root;
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
    
    int del;

    printf("Enter a Node which you want to DELETE ");
    scanf("%d",&del);
    printf("\n\n");
    root=deleteNode(root,del);
    printf("\n\n");
    print(root);
}