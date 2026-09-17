//Static Implementation of Graph

/*
#include <stdio.h>

int main() {
    
    int i, j, n, edges, u, v, arr[10][10];
    
    printf("Enter Number of Vertices in Graph - ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    
    printf("Enter Number of Edges ");
    scanf("%d",&edges);
    
    printf("\nEnter Edge for of u-v.\nu-source\nv-destination\n\n");
    
    
    for(i=0; i<edges; i++){
    printf("Enter Edge from u-v - ");
    scanf("%d%d",&u,&v);
    arr[u][v] = 1;
    arr[v][u] = 1;
    }
    
    printf("\n\n");
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
    
}
*/

//Dynamic Implementation of Graph

#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct node* arr[10];

int main(){
    int n, i, edges, u, v;
    printf("Enter How Many Elements You Want to Store in the Graph - ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        arr[i] = NULL;
    }
    
    
    printf("Enter Number of Edges ");
    scanf("%d",&edges);
    
    printf("\nEnter Edge for of u-v.\nu-source\nv-destination\n\n");
    
    
    for(i=0; i<edges; i++){
        
        printf("Enter Edge as (u v): - ");
        scanf("%d%d", &u, &v);
        struct node* newNode = malloc(sizeof(struct node));
        newNode->vertex = v;
        newNode->next = arr[u];
        arr[u] = newNode;
        
        struct node* newNode2 = malloc(sizeof(struct node));
        newNode2->vertex = u;
        newNode2->next = arr[v];
        arr[v] = newNode2;
       
    }
    
    printf("\n\nAdjecency List - \n");
    
    for(i=0; i<n; i++){
        printf("%d: ", i);
        struct node* temp = arr[i];
        
        while(temp != NULL){
            printf("%d->",temp->vertex);
            temp = temp->next;
        }
        
        printf("NULL\n");
    }
}
