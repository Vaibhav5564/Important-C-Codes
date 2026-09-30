#include<stdio.h>
#include<stdlib.h>
int main(){
    
    int allocation[5][3] = {
        {2, 3, 2},
        {4, 0, 0},
        {5, 0, 4},
        {4, 3, 3},
        {2, 2, 4}
    };
    
    int max[5][3] = {
        {9, 7, 5},
        {5, 2, 2}, 
        {1, 0, 4},
        {4, 4, 4},
        {6, 5, 5}
    };
    
    int available[] = {3, 3, 2};

    printf("\n\n1. Accept Available\n2. Display Allocation, Max\n3. Display all contents of Need Matrix\n4. Display Available\n5. Exit\n\n");
    int i, j, choice;
    
    printf("Enter Choice - ");
    scanf("%d", &choice);
    
    switch(choice){
        
        case 1:
        printf("Enter Available: ");
        scanf("%d%d%d", &available[0], &available[1], &available[2]);
        printf("\n\nAvailable Matrix Entered Successfully");
        break;

        case 2:
        printf("\n\nAllocation Matrix -\n");
        for(i=0; i<5; i++){
            for(j=0; j<3; j++){
                printf("%d\t", allocation[i][j]);
            }
            printf("\n");
        }

            printf("\n\nMaximum Matrix -\n");
            
            for(i=0; i<5; i++){
            for(j=0; j<3; j++){
                printf("%d\t", max[i][j]);
            }
            printf("\n");
        }
        printf("\nAllocation Matrix and Max Matrix Displayed Successfully");
        break;

        case 3:
        printf("\n\nContent of Need Matrix - \n");
        for(i=0; i<5; i++){
            for(j=0; j<3; j++){
                printf("%d\t", abs(max[i][j] - allocation[i][j]));
            }
            printf("\n");
        }
        printf("\n\nNeed Matrix Content Displayed Successfully");
        break;

        case 4:
        printf("Available Matrix : {%d %d %d}", available[0], available[1], available[2]);
        printf("\n\nAvailable Matrix Displayed Successfully");
        break;

        case 5:
        printf("\n\nExiting.......");
        exit(0);

        default:
        printf("\n\nInvalid Choice");
    }
}