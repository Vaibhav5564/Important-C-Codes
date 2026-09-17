#include<stdlib.h>
#include<stdio.h>

struct edge{
    
    int u, v, w;
};

int parent[10];

int find(int i){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}

void unionSet(int u, int v){
    int uRoot = find(u);
    int vRoot = find(v);
    parent[uRoot] = vRoot;
}

void kruskalMST(struct edge edges[], int e, int n){
    
    int i, j, count = 0, u, v, w, total = 0;
    for(i=0; i<n; i++){
        parent[i] = i;
    }
    for(i=0; i<e-1; i++){
        for(j=0; j<e-i-1; j++){
            if(edges[j].w > edges[j+1].w){
                struct edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
    
    printf("\n\nEdges of MST are\n\n");
    for(i = 0; count < n-1 && i < e; i++){
        u = edges[i].u; 
        v = edges[i].v;
        w = edges[i].w;
        
        if(find(u) != find(v)){
            printf("%d to %d and Weight is %d\n", u, v, w);
            unionSet(u, v);
            total += w;
            count++;
        }
    }
    printf("\nWeight of a Spanning Tree is %d", total);
}

int main(){
    int i, n, e;
    struct edge edges[10];
    
    printf("Enter No. of Vertices Present in Graph - ");
    scanf("%d", &n);
    
    printf("Enter Total No. of Edges Present in a Graph - ");
    scanf("%d", &e);
    
    printf("\n\nEnter Edges as (U V W):\nU - Source\nV - Destination\nW - Weight\n\n");
    for(i=0; i<e; i++){
        printf("Enter Edge as (U V W): ");
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    kruskalMST(edges, e, n);
}
