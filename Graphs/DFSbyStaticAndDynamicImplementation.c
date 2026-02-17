/*
#include <stdio.h>

int visited[10];


void DFS(int adj[][10], int n, int start){
    int i;
    printf("\t%d", start);
    visited[start] = 1;
    
    for(i=0; i<n; i++){
        if(adj[start][i] == 1 && visited[i] == 0){
            DFS(adj, n, i);
        }
    }
}

int main() {
    int n, edges, start, i, j, u, v, adj[10][10];
    
    printf("Enter No. of Vertices - ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        visited[i] = 0;
        for(j=0; j<n; j++){
            adj[i][j] = 0;
        }
    }
    
    printf("Enter No. of Edges ");
    scanf("%d", &edges);
    
    printf("\n\nEnter Edge as (u v):\nu: Source\nv: Destination\n\n");
    
    for(i=0; i<edges; i++){
        printf("Enter Edge (u v): ");
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    printf("\nEnter Starting Vertex - ");
    scanf("%d",&start);
    
    printf("\n\n DFS -");
    DFS(adj, n, start);

    return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

int visited[10];

void DFS(struct node* arr[], int start){
    printf("\t%d",start);
    visited[start] = 1;
    
    struct node* temp = arr[start];
    
    while(temp){
        if(visited[temp->vertex] == 0){
            DFS(arr, temp->vertex);
        }    
        temp = temp->next;
    }
}

int main(){
    int n, i, edges, u, v, start;
    struct node* arr[10];
    
    printf("Enter No. of Vertices Present in a Graph - ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        visited[i] = 0;
        arr[i] = NULL;
    }
    
    printf("Enter No. of Edges in a Graph - ");
    scanf("%d",&edges);
    
    printf("\n\nEnter Edge in The Form of (u v):\nu: Source\nv: Destination\n\n");
    
    for(i=0; i<edges; i++){
        printf("Enter edge as (u v):  ");
        scanf("%d%d", &u, &v);
        
        struct node* newNode1 = malloc(sizeof(struct node));
        newNode1->vertex = v;
        newNode1->next = arr[u];
        arr[u] = newNode1;
        
        struct node* newNode2 = malloc(sizeof(struct node));
        newNode2->vertex = u;
        newNode2->next = arr[v];
        arr[v] = newNode2;
    }
    
    printf("Enter Starting Vertex - ");
    scanf("%d",&start);
    
    printf("\n\nDFS -");
    DFS(arr, start);
    
}