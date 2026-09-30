#include <stdio.h>
#include <stdlib.h>

int bit[20];
int file[10][20];
char name[10][20];
int size[10], nfiles = 0;

void showBit() {
    int i;

    printf("Bit Vector: ");
    for(i = 0; i < 20; i++)
        printf("%d ", bit[i]);

    printf("\n");
}

void createFile() {
    int n, i, j = 0;

    printf("Enter file name: ");
    scanf("%s", name[nfiles]);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    for(i = 0; i < 20 && j < n; i++) {
        if(bit[i] == 0) {
            bit[i] = 1;
            file[nfiles][j] = i;
            j++;
        }
    }

    if(j < n) {
        printf("Not enough free blocks\n");
        return;
    }

    size[nfiles] = n;
    nfiles++;

    printf("File created\n");
}

void showDirectory() {
    int i, j;

    for(i = 0; i < nfiles; i++) {
        printf("%s: ", name[i]);

        for(j = 0; j < size[i]; j++)
            printf("%d -> ", file[i][j]);

        printf("NULL\n");
    }
}

int main() {
    int choice, i;

    /* 0 = free, 1 = allocated */
    for(i = 0; i < 20; i++)
        bit[i] = i % 2;

    while(1) {
        printf("\n1. Show Bit Vector");
        printf("\n2. Create New File");
        printf("\n3. Show Directory");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                showBit();
                break;

            case 2:
                createFile();
                break;

            case 3:
                showDirectory();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}