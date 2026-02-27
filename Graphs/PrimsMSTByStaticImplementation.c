#include<stdio.h>
#define RANDOM 999
int visited[10], key[10], parent[10];


int minDist(int n){
    int i, minInd = -1, min = RANDOM;
    
    for(i=0; i<n; i++){
        if(!visited[i] && key[i] < min){
            min = key[i];
            minInd = i;
        }
    }
    return minInd;
}

void primsMST(int cost[10][10], int n){
    
    int i, u, v, total = 0;
    
    key[0] = 0;
    parent[0] = -1;
    
    for(i=0; i<n-1; i++){
        u = minDist(n);
        if(u == -1){
            break;
        }
        visited[u] = 1;
        for(v=0; v<n; v++){
            if(!visited[v] && cost[u][v] && cost[u][v] < key[v]){
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }
    printf("\nEdges in Spanning Trees are - \n\n");
    for(i=1; i<n; i++){
        printf("Edge %d to %d and weight is %d\n", parent[i], i, cost[i][parent[i]]);
        total+=cost[i][parent[i]];
    }
    printf("\n\nTotal weight of a Spanning Tree is %d", total);
}

int main(){
    int i, j, n, cost[10][10];
    
    printf("Enter No. of Vertices Present in Graph - ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        visited[i] = 0;
        key[i] = RANDOM;
        parent[i] = 0;
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Enter Cost/Weight of Edge (%d-%d) if Exist else print 0 ", i, j);
            scanf("%d",&cost[i][j]);
        }
    }
    
    primsMST(cost, n);
}