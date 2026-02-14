/*a) Write a C program which uses Binary search tree library and display the following 
i. Node value at each level
ii. Count of node at each level
iii. Total levels in the tree.*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* left ;
    int data ;
    struct node* right ;
};
int front = 0 , rear = -1;
struct node* arr[100];

 

void enque(struct node* root){
    rear+=1;
    arr[rear] = root;
}
struct node* deque(){
    if(front > rear){
        return NULL;
    }
    return arr[front++];
}

struct node* createNode(struct node* root , int data){
    if(root==NULL){
        root = malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data){
        root->left = createNode(root->left,data);
    }
    else if(data > root->data){
        root->right = createNode(root->right,data);
    }
    else{
        printf("Duplicates Not Allowed");
    }
    return root;
}
void print(struct node* root){
    if(root == NULL){
        return;
    }
    print(root->left);
    printf("--%d--",root->data);
    print(root->right);
}

void nodeAtLevel(struct node* root){
    if(root == NULL){
        return;
    }
    int counter = 0 , level = 0;
    enque(root);
    enque(NULL);
    while(front <= rear){
        struct node* temp = deque();
        if(temp == NULL){
            printf("\t\tNo. of Nodes at Level %d is %d\n",level,counter);
            counter = 0;
            level++;
            if(front <= rear){
                enque(NULL);
            }
        }
        else{
            printf("--%d--",temp->data);
            counter++;
            if(temp->left != NULL){
                enque(temp->left);
            }
            if(temp->right != NULL){
                enque(temp->right);
                
            }
        }
    }
}
struct node* max(struct node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL){
        return root;
    }
    return max(root->right);
}

struct node* min(struct node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){
        return root;
    }
    return min(root->left);
}
int main(){
    int n , i , data ;
    struct node* root = NULL;
    printf("Enter How Many Elements You Want to add in TREE ");
    scanf("%d",&n);
    for(i=1 ; i<=n ; i++){
        printf("Enter Element %d - ",i);
        scanf("%d",&data);
        root=createNode(root,data);
    }
    print(root);
    printf("\n\nNodes Traversing Level Wise\n\n");
    nodeAtLevel(root);
    printf("\nMaximum Element in Tree is %d",max(root)->data);
    printf("\nMinimum Element in Tree is %d",min(root)->data);
}