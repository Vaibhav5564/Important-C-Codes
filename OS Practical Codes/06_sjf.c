#include<stdio.h>
int main(){
    int i, j, n, temp;
    int bt[20], wt[20], tat[20];

    printf("Enter Number of Process - ");
    scanf("%d", &n);

    printf("\n\nEnter Burst Time\n\n");

    for(i=0; i<n; i++){
        printf("P%d - ", i);
        scanf("%d", &bt[i]);
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(bt[j]<bt[i]){
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
        tat[i] = bt[i]+wt[i];
    }

    printf("Burst Time\tWaiting Time\tTurn-Around Time\n\n");

    for(i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\n", bt[i], wt[i], tat[i]);
    }

    return 0;
}