#include<stdio.h>

int main(){
    int n, i;
    int bt[20], wt[20], tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\n\nEnter Burst Time\n\n");

    for(i=0; i<n; i++){
        printf("P%d - ", i);
        scanf("%d", &bt[i]);
    }
    printf("\n");

    wt[0] = 0;

    for(i=1; i<n; i++){
        wt[i] = wt[i-1]+bt[i-1];
    }

    for(i=0; i<n; i++){
        tat[i] = wt[i]+bt[i];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    
    for(i=0; i<n; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    return 0;
}