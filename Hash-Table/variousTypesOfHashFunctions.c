/* a) Write a program to implement various types of hash functions which are used to place the 
 data in a hash table
 a. Division Method
 b. Mid Square Method
 c. Digit Folding Method
 Accept n values from the user and display appropriate message in case of collision for each of 
the above functions.*/



#include<stdio.h>

#define MAX 100

int division[MAX];
int mid[MAX];
int fold[MAX];

void initialise(){
    int i;
    for(i=0; i<MAX; i++){
        division[i] = -1;
        mid[i] = -1;
        fold[i] = -1;
    }
}

int divInd(int n){
    return n % MAX;
}

void divMethod(int key){
    int ind, org;
    ind = divInd(key);
    org = ind;
    
    while(division[ind] != -1){
        printf("\nCollision is Occured (In Division Method)\n");
        ind = (ind + 1) % MAX;
        if(org == ind){
            printf("\n\nHash Table is FULL");
            return;
        }
    }
    division[ind] = key;
}

int midInd(int n){
    
    int sq = n * n;
    
    if(n < 10)
       return sq % MAX;
    
    sq /= 10;
    int rem = sq % 100;
    
    return rem % MAX;
}

void midMethod(int key){
    int ind, org;
    ind = midInd(key);
    org = ind;
    
    while(mid[ind] != -1){
        printf("\nCollision is Occured (In Mid Square Method)\n");
        ind = (ind + 1) % MAX;
        if(org == ind){
            printf("\n\nHash Table is FULL");
            return;
        }
    }
    mid[ind] = key;
}

int foldInd(int n){
    int sum = 0;
    while(n>0){
        int rem = n % 100;
        n /= 100;
        sum += rem;
    }
    return sum % MAX;
}

void foldMethod(int key){
    int ind, org;
    ind = foldInd(key);
    org = ind;
    
    while(fold[ind] != -1){
        printf("\nCollision is Occured (In Folding Method)\n");
        ind = (ind + 1) % MAX;
        if(org == ind){
            printf("\n\nHash Table is FULL");
            return;
        }
    }
    fold[ind] = key;
}

void display(int arr[]){
    int i;
    for(i=0; i<MAX; i++){
        if(arr[i] == -1)
            printf("NULL -> ");
        else
            printf("%d -> ", arr[i]);
    }
    printf("End");
}

int main(){
    int i, n, key, ch;
    
    printf("Enter Total No. of Keys - ");
    scanf("%d", &n);
    
    initialise();
    
    
    for(i=0; i<n; i++){
    printf("Enter key - ");
    scanf("%d", &key);
    
    divMethod(key);
    midMethod(key);
    foldMethod(key);
    }
    
    printf("\n\n1. Division Method\n2. Mid Square Method\n3. Folding Method\n\n");
    printf("Enter Choice - ");
    scanf("%d", &ch);
    
    switch(ch){
        case 1:
        printf("\n\nHash table by Division Method\n\n");
        display(division);
        break;
        
        case 2:
        printf("\n\nHash table by Mid Square Method\n\n");
        display(mid);
        break;
        
        case 3:
        printf("\n\nHash table by Folding Method\n\n");
        display(fold);
        break;
        
        default:
        printf("\nInvalid Choice");
    }
}