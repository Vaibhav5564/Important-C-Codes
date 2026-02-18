
// #include <stdio.h>

// int visited[10];
// int dist[10];

// int minDis(int n){
//     int i, min = 999, minInd = -1;
    
//     for(i=0; i<n; i++){
//         if(!visited[i] && dist[i] < min){
//             min = dist[i];
//             minInd = i;
//         }
//     }
//     return minInd;
// }

// void dijkastra(int cost[][10], int src, int n){
//     int i, u, v;
    
//     for(i=0; i<n; i++){
//         visited[i] = 0;
//         dist[i] = 999;
//     }
//     dist[src] = 0;
    
//     for(i=0; i<n-1; i++){
//         u = minDis(n);
//         if(u == -1){
//             break;
//         }
//         visited[u] = 1;
//         for(v=0; v<n; v++){
//             if(!visited[v] && cost[u][v] != 999 && dist[u] + cost[u][v] < dist[v]){
//                 dist[v] = dist[u] + cost[u][v];
//             }
//         }
//     }
//     printf("\n\nDistance From Source To All Other Vertices Are - \n\n");
    
//     for(i=0; i<n; i++){
    
//             printf("Distance from %d to %d is %d\n", src, i, dist[i]);
        
//     }
// }

// int main() {
    
//     int i, j, n, src, cost[10][10];
    
//     printf("Enter How Many Vertices in a Graph - ");
//     scanf("%d",&n);
    
//     printf("\n\nEnter Weight Between Two Vertex\nIf There is no Edge then Write 999");
    
//     for(i=0; i<n; i++){
//         for(j=0; j<n; j++){
//             printf("Enter Weight between %d to %d",i,j);
//             scanf("%d",&cost[i][j]);
//         }
//     }
    
//     printf("\n\nEnter a Source Vertex -");
//     scanf("%d",&src);
    
//     dijkastra(cost, src, n);

//     return 0;
// }

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