#include<stdio.h>
#define INF 999
void floyWarshall(int cost[10][10], int n){
    int i, j, k;
    
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(cost[i][k] + cost[k][j] < cost[i][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    
    printf("\n\nShortest Paths Matrix -\n\n");
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(cost[i][j] == INF){
                printf("INF\t");
            }
            else{
                printf("%3d\t", cost[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    
    int i, j, edges, n, cost[10][10];
    
    printf("Enter Total No. of Vertex Present in Graph - ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++){
        printf("\t");
        for(j=0; j<n; j++){
            printf("Enter Weight Between %d to %d If There is No Edge Present Between Them then Print 999\n");
            scanf("%d", &cost[i][j]);
        }
    }
    floyWarshall(cost, n);
}