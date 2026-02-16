//Calculate Indegree and Outdegree of All the Vertices
/*#include <stdio.h>

int main() {
    int adj[10][10], indegree, outdegree, n, data, i, j, edges, u, v;
    
    printf("No. of Vertex Present in Graph - ");
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            adj[i][j] = 0;
        }
    }
    
    printf("Enter No. of Edges ");
    scanf("%d",&edges);
    
    printf("\n\nEnter Edges as (u v): means u -> v\n\n");
    
    for(int i=0 ; i<edges ; i++){
        printf("Enter Edge (u v): ");
        scanf("%d%d",&u,&v);
        adj[u][v] = 1;
    }
    
    printf("\nAdjecency Matrix\n\n");
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\nvertex\tinDeg.\toutDeg.\ttotalDeg.\n");
    for(i=0; i<n; i++){
        indegree = 0, outdegree = 0;
        for(j=0; j<n; j++){
            if(adj[i][j] == 1){
                outdegree++;
            }
            if(adj[j][i] == 1){
                indegree++;
            }
        }
        printf("\n\t%d\t\t%d\t\t%d\t\t%d",i,indegree,outdegree,indegree+outdegree);
    }
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node* nxt;
};
int main(){
    int n, i, edges, u, v;
    
    printf("Enter How many Vertices are in Graph ");
    scanf("%d",&n);
    
    int indegree[n], outdegree[n];
    
    for(i=0; i<n; i++){
        indegree[i] = 0;
        outdegree[i] = 0;
    }
    struct node* arr[n];
    
    for(i=0; i<n; i++){
        arr[i] = NULL;
    }
    
    printf("Enter How Many Edges in a Graph - ");
    scanf("%d",&edges);
    
    printf("\n\nEnter Edges as (u v): means u -> v \n\n");
    
    for(i=0; i<edges; i++){
        printf("Enter Edge (u v): ");
        scanf("%d%d", &u, &v);
        
        struct node* newNode = malloc(sizeof(struct node));
        newNode->vertex = v;
        newNode->nxt = arr[u];
        arr[u] = newNode;
        
        indegree[v]++ ;
        outdegree[u]++ ;
    }
    
    printf("\n\n");
    
    for(i=0; i<n; i++){
        struct node* tmp = arr[i];
        while(tmp != NULL){
            printf("%d -> ",tmp->vertex);
            tmp = tmp->nxt;
        }
        printf("NULL\n");
    }
    printf("\n\nvertex\tinDeg.\toutDeg\ttotalDeg.\n");

    for(i=0; i<n; i++){
        printf("\n\t%d\t\t%d\t\t%d\t\t%d",i,indegree[i],outdegree[i],indegree[i]+outdegree[i]);
    }
}