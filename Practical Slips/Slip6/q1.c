#include <stdio.h>
#include <stdlib.h>

int bit[20];
char name[10][20];
int start[10], size[10], nfiles = 0;

void showBit() {
    int i;

    printf("Bit Vector: ");
    for(i = 0; i < 20; i++)
        printf("%d ", bit[i]);

    printf("\n");
}

void createFile() {
    int n, i, j, found;

    printf("Enter file name: ");
    scanf("%s", name[nfiles]);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    found = -1;

    for(i = 0; i <= 20 - n; i++) {
        for(j = 0; j < n; j++)
            if(bit[i + j] == 1)
                break;

        if(j == n) {
            found = i;
            break;
        }
    }

    if(found == -1) {
        printf("Not enough consecutive blocks\n");
        return;
    }

    start[nfiles] = found;
    size[nfiles] = n;

    for(i = found; i < found + n; i++)
        bit[i] = 1;

    nfiles++;

    printf("File created\n");
}

void showDirectory() {
    int i;

    printf("\nDirectory:\n");

    for(i = 0; i < nfiles; i++)
        printf("%s : Start = %d, Blocks = %d\n",
               name[i], start[i], size[i]);
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