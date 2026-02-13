/*a) Implement a Binary search tree (BST) library (btree.h) with operations  – create, search,insert, inorder, preorder and postorder. Write a menu  driven program that performs the above operations.*/

/*b) Find Total Number of Nodes and Leaf Nodes */

#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* left;
    int data;
    struct node* right;
};

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

void inorder(struct node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d -> ",root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    printf("%d -> ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ",root->data);
}

int search(struct node* root , int key){
    if(root == NULL){
        return 0;
    }
    if(root->data == key){
        return 1;
    }
    if(key < root->data){
        return search(root->left , key);
    }
    else{
        return search(root->right , key);
    }
}

int countNodes(struct node *root){
    if(root == NULL){
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(struct node* root){
    if(root == NULL){
        return 0;
    }    
    if(root->left==NULL  && root->right==NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main(){
    int n , i , choice , data , key;
    struct node* root = NULL;
    printf("Enter How Many Elements You Want to Add in BST  ");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++){
        printf("Enter Element %d - ",i);
        scanf("%d",&data);
        root = createNode(root,data);
    }
    printf("\n\n1.Preorder\n2.Inorder\n3.Postorder\n4.Search\n5.Count Total Number of Nodes\n6.Count Total Number of Leaf Nodes\n7.Exit()\n");
    do{
        printf("\nEnter Choice ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            preorder(root);
            break;
        
        case 2:
            inorder(root);
            break;
        
        case 3:
            postorder(root);
            break;
        
        case 4:
            printf("Enter Element You Want to Search ");
            scanf("%d",&key);
            if(search(root,key)){
                printf("Element is Present in Tree\n");
            }
            else{
            printf("Element is NOT Present in Tree\n");
            }
            break;
            
            case 5:
            printf("Total Number of Nodes are %d ",countNodes(root));
            break;
            
            case 6:
            printf("Total Number of Leaf Nodes are %d ",countLeafNodes(root));
            break;
            
        case 7:
            exit(0);
        
        default:
            printf("Entered Invalid Choice");
        
   }
 }while(choice != 7);
 
}