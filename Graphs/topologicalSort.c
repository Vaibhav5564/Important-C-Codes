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