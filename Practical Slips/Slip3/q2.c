#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, movement = 0;
    int min, pos, diff;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int request[n], visited[n];

    printf("Enter request string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &request[i]);
        visited[i] = 0;
    }

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Service Order: ");

    for(i = 0; i < n; i++) {
        min = 9999;

        for(j = 0; j < n; j++) {
            if(visited[j] == 0) {
                diff = abs(head - request[j]);

                if(diff < min) {
                    min = diff;
                    pos = j;
                }
            }
        }

        visited[pos] = 1;
        movement += min;
        head = request[pos];

        printf("%d ", head);
    }

    printf("\nTotal Head Movement = %d\n", movement);

    return 0;
}