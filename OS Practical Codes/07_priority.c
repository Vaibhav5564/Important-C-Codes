#include<stdio.h>

int main(){
    int i, j, n, temp;
    int bt[20], wt[20], tat[20], priority[20];

    printf("\n\nEnter No. of Processes - ");
    scanf("%d", &n);

    printf("\n\nEnter Burst Time And Priority\n\n");

    for(i=0; i<n; i++){
        printf("P%d - ", i);
        scanf("%d%d", &bt[i], &priority[i]);
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(priority[i]<priority[j]){
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(i=1; i<n; i++){
        wt[i] = wt[i-1]+bt[i-1];
    }

    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }

    printf("\n\nPriority\tBurst Time\tWaiting Time\tTurn-Around Time\n");

    for(i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n", priority[i], bt[i], wt[i], tat[i]);
    }
    return 0;
}