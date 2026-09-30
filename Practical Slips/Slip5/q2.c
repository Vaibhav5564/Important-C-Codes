#include <stdio.h>

int main() {
    int n, m, i, j, p;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], req[10];

    printf("Enter processes: ");
    scanf("%d", &n);

    printf("Enter resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    /* Need = Max - Allocation */
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nEnter process number for request: ");
    scanf("%d", &p);

    printf("Enter Request:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &req[j]);

    /* Check Request <= Need and Request <= Available */
    for(j = 0; j < m; j++) {
        if(req[j] > need[p][j] || req[j] > avail[j]) {
            printf("Request cannot be granted immediately\n");
            return 0;
        }
    }

    printf("Request can be granted immediately\n");

    return 0;
}