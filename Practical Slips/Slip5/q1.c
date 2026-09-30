#include <stdio.h>

int main() {
    int n, pages[20], frame[10];
    int i, j, k = 0, fault = 0, hit;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter number of pages: ");
    int p;
    scanf("%d", &p);

    printf("Enter reference string: ");
    for(i = 0; i < p; i++)
        scanf("%d", &pages[i]);

    for(i = 0; i < n; i++)
        frame[i] = -1;

    for(i = 0; i < p; i++) {
        hit = 0;

        for(j = 0; j < n; j++) {
            if(frame[j] == pages[i]) {
                hit = 1;
                break;
            }
        }

        if(hit == 0) {
            frame[k] = pages[i];
            k = (k + 1) % n;
            fault++;
        }

        printf("\nPage %d: ", pages[i]);

        for(j = 0; j < n; j++)
            printf("%d ", frame[j]);

        if(hit == 0)
            printf(" Page Fault");
        else
            printf(" Hit");
    }

    printf("\n\nTotal Page Faults = %d\n", fault);

    return 0;
}