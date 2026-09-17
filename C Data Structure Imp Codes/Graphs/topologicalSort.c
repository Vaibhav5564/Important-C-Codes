
// #include <stdio.h>

// int visited[10], stack[10], top = -1;

// void push(int data){
//     stack[++top] = data;
// }

// int pop(){
//     return stack[top--];
// }

// void topologicalSort(int adj[][10], int curr, int n){
//     int i;
//     visited[curr] = 1;
//     for(i=0; i<n; i++){
//         if(adj[curr][i] == 1 && visited[i] == 0)
//         {
//             topologicalSort(adj, i, n);
//         }
//     }
//     push(curr);
// }
// int main() {
    
//     int n, i, j, u, v, edges, adj[10][10];
    
//     printf("Enter How Many Vertices is in Graph - ");
//     scanf("%d",&n);
    
//     for(i=0; i<n; i++){
//         for(j=0; j<n; j++){
//             adj[i][j] = 0;
//         }
//     }
    
//     printf("Enter No. of Edges in a Graph - ");
//     scanf("%d",&edges);
    
//     printf("Enter Edges as (u v):\nwhere\nu--->v\n\n");
    
//     for(i=0; i<edges; i++){
//         printf("Enter edge as (U V): - ");
//         scanf("%d%d", &u, &v);
//         adj[u][v] = 1;
//     }
    
//     printf("\n\nTopological Sort -");
    
//     for(i=0; i<n; i++){
//      if(visited[i] == 0){
//         topologicalSort(adj, i, n);
//     }
// }
    
//     while(top >= 0){
//         printf("\t%d",stack[top]);
//         top--;
//     }
  
//     return 0;
// }

#include <stdlib.h>
#include <stdio.h>

struct node{
    int vertex;
    struct node* next;
};

int visited[10], stack[10], top=-1;


void push(int data){
    stack[++top] = data;
}

int pop(){
    return stack[top--];
}

void topologicalSort(struct node* arr[], int curr){
    
    visited[curr] = 1;
    int count = 0;  //Took this To Understand How Many Elements Visited to Each Call
    struct node* temp = arr[curr];
    
    while(temp){
        if(!visited[temp->vertex]){
            count++;
            topologicalSort(arr, temp->vertex);
        }
        temp = temp->next;
    }
    printf("%d\n",count);
    push(curr);
}

int main() {
    
    int n, i, vertex, edges, start, u, v;
    struct node* arr[10];
    
    printf("Enter No. of Vertices in a Graph ");
    scanf("%d",&n);
    
    printf("\nEnter No. of Edges in a Graph ");
    
    printf("Enter Edge as (u v):\nu: Source\nv: Destination\n\n");
    
    for(i=0; i<n; i++){
        arr[i] = NULL;
        visited[i] = 0;
    }
        printf("\nEnter No. of Edges in a Graph ");
        scanf("%d",&edges);
    
        printf("Enter Edge as (u v):\nu: Source\nv: Destination\n\n");
        
        for(i=0; i<edges; i++){
        printf("Enter Edge as (u v): - ");
        scanf("%d%d", &u, &v);
        
        struct node* newNode1 = malloc(sizeof(struct node));
        newNode1->vertex = v;
        newNode1->next = arr[u];
        arr[u] = newNode1;
    }
    
     // Run DFS for all vertices
    for(i=0; i<n; i++){
        if(!visited[i]){
            topologicalSort(arr, i);
        }
    }
    
    printf("\n\nTopological Sort -");
    while(top != -1){
        printf("\t%d",pop());
    }
  
    return 0;
}