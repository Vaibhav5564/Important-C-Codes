/* b) Write a C program to implement a hash table using separate chaining with linked lists with 
following operation.
a. Insert a key
b. Search a key
c. Delete a key
d. Display the hash table */

#include <stdlib.h>
#include <stdio.h>
#define MAX 10


struct node {
    int data;
    struct node* next;
};

struct node* arr[MAX];

int divideInd(int key){
    return key % MAX;
}

void insert(int data){
    int ind = divideInd(data);
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = arr[ind];
    arr[ind] = newNode;
    printf("\nKey is Inserted\n");
}

void search(int key){
    int ind = divideInd(key);
    struct node* temp = arr[ind];
    while(temp != NULL){
        if(temp->data == key){
            printf("\nElemnet is Present in Hash Table\n");
            return;
        }
        temp = temp->next;
    }
    printf("\nOppps Element is not present in Hash Table\n");
}

void deleteKey(int key){
    int ind = divideInd(key);
    struct node* temp = arr[ind];
    struct node* prev = NULL;
    while(temp != NULL){
        if(temp->data == key){
            if(prev == NULL){
                arr[ind] = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            free(temp);
            printf("\n\nKey is Deleted\n\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nKey is Not Present in Hash Table\n");
}


void display(){
    for(int i=0; i<MAX; i++){
        printf("[%d] -> ", i);
        struct node* temp = arr[i];

        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main(){
    
    int i;
    
    for(i=0; i<MAX; i++) arr[i] = NULL;
    
    int ch, data, key;
    
    printf("\n\n1. Insert a Key\n2. Search a Key\n3. Delete a Key\n4. Display Hash Table\n");
    
    do{
        printf("\nEnter Choice - ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
            printf("\nEnter a Key - ");
            scanf("%d", &data);
            insert(data);
            break;
            
            case 2:
            printf("Enter a Key Which You Want to Search - ");
            scanf("%d", &key);
            search(key);
            break;
            
            case 3:
            printf("Enter a Key Which You Want to Delete - ");
            scanf("%d", &key);
            deleteKey(key);
            break;
            
            case 4:
            printf("\n");
            display();
            break;
            
            case 5:
            printf("\n\n||Exiting||\n");
            return 0;
            
            default:
            printf("\nWrong Choice !!!!!!! Enter Valid Choice\n");
        }
    }while(ch != 5);    
}