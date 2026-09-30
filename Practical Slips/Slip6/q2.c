#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {15,45,75,105,135,165,195,80};
    int n = 8;
    int head = 100;
    int movement = 0;
    int i, j, temp;

    /* Sort */
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("Service Order: ");

    /* Move Right */
    for(i = 0; i < n; i++) {
        if(a[i] >= head) {
            printf("%d ", a[i]);
            movement += abs(head - a[i]);
            head = a[i];
        }
    }

    /* Go to end of disk */
    movement += 199 - head;
    head = 199;

    /* Jump to beginning */
    movement += 199;
    head = 0;

    /* Continue Right */
    for(i = 0; i < n; i++) {
        if(a[i] < 100) {
            printf("%d ", a[i]);
            movement += abs(head - a[i]);
            head = a[i];
        }
    }

    printf("\nTotal Head Movement = %d\n", movement);

    return 0;
}