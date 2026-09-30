#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, temp, movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter requests: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    // Sort requests
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("Service Order: ");

    // Move left
    for(i = n - 1; i >= 0; i--) {
        if(a[i] < head) {
            printf("%d ", a[i]);
            movement += abs(head - a[i]);
            head = a[i];
        }
    }

    // Move right
    for(i = 0; i < n; i++) {
        if(a[i] > head) {
            printf("%d ", a[i]);
            movement += abs(head - a[i]);
            head = a[i];
        }
    }

    printf("\nTotal Head Movement = %d\n", movement);

    return 0;
}