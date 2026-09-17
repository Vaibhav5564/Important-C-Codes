/* a) Write a C program to implement a hash table using open addressing with linear probing.perform the following operations.( Assume all keys are positive integers)
a. Insert
b. Search
c. Delete
d. Display */


#include <stdio.h>
#define MAX 10

int hash[MAX];

int lProbing(int key){
    return key % MAX;
}

void insert(int key){
    int ind = lProbing(key);
    int org = ind;
    
    while(hash[ind] != -1 && hash[ind] != -2){
        printf("\nCollision Occurs at Index %d\n", ind);
        ind = (ind + 1) % MAX;
        if(ind == org){
            printf("\nHash Table is FULL\n");
            return;
        }
    }
    hash[ind] = key;
    return;
}

void search(int key){
    int ind = lProbing(key);
    int org = ind;
    while(hash[ind] != -1){
        if(hash[ind] == key){
            printf("\nElement is Present in the Hash Table\n");
            return;
        }
        ind = (ind + 1) % MAX;
        
        if(ind == org){
            printf("\nElement is Not Present in Hash Table\n");
            return;
        }
    }
    printf("\nElement is Not Present in Hash Table\n");
    return;
}

void del(int key){
    int ind = lProbing(key);
    int org = ind;
    while(hash[ind] != -1){
        if(key == hash[ind]){
            printf("\nKey is Deleted From Hash Table\n");
            hash[ind] = -2;
            return;
        }
        ind = (ind + 1) % MAX;
        
        if(ind == org){
            printf("\nElement is Not Present in Hash Table\n");
            return;
        }
    }
     printf("\nElement is Not Present in Hash Table\n");
     return;
}

void display(){
    int i;
    for(i=0; i<MAX; i++){
        if(hash[i] != -1 && hash[i] != -2) printf(" %d ", hash[i]);
    }
}

void main(){
    
    int data, ch, i;
    
    for(i=0; i<MAX; i++){
        hash[i] = -1;
    }
    
    printf("\n1. Insert\n2. Search\n3. Delete\n4. display\n5. Exit\n");
    
    do{
        printf("\nEnter Choice - ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("\nEnter Key Which you Want to Insert - ");
            scanf("%d", &data);
            insert(data);
            break;
            
           case 2:
            printf("\nEnter Key Which you Want to Search - ");
            scanf("%d", &data);
            search(data);
            break;
            
            case 3:
            printf("\nEnter Key Which you Want to Delete - ");
            scanf("%d", &data);
            del(data);
            break;
            
            case 4:
            printf("\nHash Table\n\n");
            display();
            break;
            
            case 5:
            printf("\n\n||||||| EXITING |||||||");
            return ;
            
            default:
            printf("\n\nInvalid Choice\n");
        }
    }while(ch != 5);
}