//Static Implementation of Tree and BFS Traversal
/*
#include<stdio.h>

int rear = 0 , front = 0;

int queue[100];

void enqueue(int data){
    queue[rear] = data;
    rear++;
}

int dequeue(){
    int data = queue[front];
    front++;
    return data;
}

void BFS(int arr[][10], int n){
    
    front = rear = 0 ;
    int i, start, visited[n];
    for(i=0 ; i<n ; i++){
        visited[i] = 0;
    }
    
    printf("Enter Starting Vertex ");
    scanf("%d",&start);
    
    enqueue(start);
    visited[start] = 1;
    
    while(front < rear){
        
        int current = dequeue();
        
        printf("%d\t",current);
        
        for(i=0 ; i<n ; i++){
            if(arr[current][i] == 1 && visited[i] == 0){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main(){
    
    int i, j, n, u, v, edges, arr[10][10];
    
    printf("Enter No. of Vertices - ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        for(j=0 ; j<n; j++){
            arr[i][j]=0;
        }
    }
    printf("Enter No. of Edges - ");
    scanf("%d",&edges);
    
    printf("\n\nEnter Edges in Form of u-v\nu.source vertex\nv.destination vertex\n\n");
    
    
    for(i=0; i<edges; i++){
        printf("Enter Edge as (u v): ");
        scanf("%d%d",&u,&v);
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    
    BFS(arr,n);
    
    
    return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* next;
};
int front=0, rear=0, queue[100] ;

void enqueue(int data){
    queue[rear++] = data;
}

int dequeue(){
    return queue[front++];
}

void BFS(struct node* arr[], int n){
    int visited[n];
    int i;
    for(i=0 ; i<n ; i++){
        visited[i] = 0;
    }
    int start;
    printf("Enter Starting Node ");
    scanf("%d",&start);
    
    enqueue(start);
    visited[start] = 1;
    
    while(front < rear){
        int current = dequeue();
        printf("%d\t", current);
        
        struct node* tmp = arr[current];
        
        while(tmp != NULL){
        if(visited[tmp->vertex] == 0){
            enqueue(tmp->vertex);
            visited[tmp->vertex] = 1;
        }
        tmp = tmp->next;
    }
  }
}

int main(){
    int i, n, u, v, edges;
    printf("Enter No. of Vertices - ");
    scanf("%d",&n);
    
    struct node* arr[n];
    
    for(i=0; i<n; i++){
        arr[i] = NULL;
    }
    
    printf("Enter No. of Edges - ");
    scanf("%d",&edges);
    
    printf("\n\nEnter Edges in Form of u-v\nu.source vertex\nv.destination vertex\n\n");
    
    for(i=0 ; i<edges ; i++){
        printf("Enter Edge is Form of (u v): ");
        scanf("%d%d",&u,&v);
        struct node* newNode = malloc(sizeof(struct node));
        newNode->vertex = v;
        newNode->next = arr[u];
        arr[u] = newNode;
        
        struct node* newNode2 = malloc(sizeof(struct node));
        newNode2->vertex = u;
        newNode2->next = arr[v];
        arr[v] = newNode2;
    }
    
    printf("BFS - \n");
    BFS(arr,n);
    
}
