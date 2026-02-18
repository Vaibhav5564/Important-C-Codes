#include<stdio.h>
#include<stdlib.h>
struct node{
    int vertex, weight;
    struct node* next;
};

int INVALID = 9999;  

int visited[10], dist[10];

int minDist(int n){
    int i, min = INVALID, minIndex = -1;
    
    for(i=0; i<n; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkastra(struct node* arr[], int source, int n){
    
    int i;
    
    for(i=0; i<n; i++){
        visited[i] = 0;
        dist[i] = INVALID;
    }
    
    dist[source] = 0;
    
    for(i=0; i<n-1; i++){
        
        int u = minDist(n);
        if(u == -1){
           break;
        }
        visited[u] = 1;
        struct node* temp = arr[u];
        
        while(temp){
            int v = temp->vertex;
             int weight = temp->weight;
             if(!visited[v] && dist[u] + weight < dist[v]){
                 dist[v] = dist[u] + weight;
             }
             temp = temp->next;
        }
    }
    printf("\n\nDijkstra's Algorithm\n\n");
    
    for(i=0; i<n; i++){
        printf("Minimum Path from Vertex %d to %d is %d\n",source, i, dist[i]);
    }
}

int main(){
    int i, u, v, w, n, edges, source;
    struct node* arr[10];
    
    printf("Enter No. of Vertex ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        arr[i] = NULL;
    }
    
    printf("\nEnter No. of Edges - ");
    scanf("%d", &edges);
    
    printf("\n\nEnter Edge as (U V W): Means U-pointing->V and W - Weight\n\n");
    
    for(i=0; i<edges; i++){
        
        printf("Enter edge as (u v w) - ");
        scanf("%d%d%d", &u, &v, &w);
        
        struct node* newNode = malloc(sizeof(struct node));
        newNode->vertex = v;
        newNode->weight = w;
        newNode->next = arr[u];
        arr[u] = newNode;
    }
        printf("Enter Source Vertex - ");
        scanf("%d",&source);
        dijkastra(arr, source, n);
}