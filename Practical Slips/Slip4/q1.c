#include <stdio.h>

int main() {
    int n, m, i, j;
    int allocation[10][10], max[10][10], need[10][10], available[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &available[j]);

    /* Need = Max - Allocation */
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    printf("\nAllocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable:\n");
    for(j = 0; j < m; j++)
        printf("%d ", available[j]);

    return 0;
}