#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter request string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Service Order: ");

    for(i = 0; i < n; i++) {
        printf("%d ", request[i]);

        movement += abs(head - request[i]);
        head = request[i];
    }

    printf("\nTotal Head Movement = %d\n", movement);

    return 0;
}