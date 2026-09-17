#include<stdio.h>

int main(){
    int i, n, tq, done, time = 0;
    int bt[20], wt[20]= {0}, tat[20], rem[20];

    printf("Enter Total No. of Processes - ");
    scanf("%d", &n);

    printf("\n\nEnter Burst Time\n\n");

    for(int i=0; i<n; i++){
        printf("P%d - ", i);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("\nEnter Time Quantum - ");
    scanf("%d", &tq);
    
    do{
       done = 1; 

       for(i=0; i<n; i++){
        if(rem[i] > 0){
            done = 0;
            if(rem[i]>tq){
                time += tq;
                rem[i] -= tq;
            }
            else{
                time += rem[i];
                wt[i] = time - bt[i];
                rem[i] = 0;
                } 
            }
        }
    }while(done == 0);

    for(i=0; i<n; i++){
        tat[i] = bt[i]+wt[i];
    }
    printf("Process\t\tBurst Time\tWaiting Time\tTurn-Around Time\n");

    for(i=0; i<n; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    return 0;
}