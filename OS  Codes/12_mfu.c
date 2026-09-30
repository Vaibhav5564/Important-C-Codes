#include <stdio.h>

int main()
{
    int pages[20], frames[10], freq[10];
    int n, f, i, j;
    int hit, faults = 0, pos, max;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        freq[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        hit = 0;

        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                hit = 1;
                freq[j]++;
                break;
            }
        }

        if(hit == 0)
        {
            faults++;
            pos = -1;
            max = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                if(freq[j] > max)
                {
                    max = freq[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            freq[pos] = 1;
        }

        printf("\n");
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nPage Faults = %d\n", faults);
    printf("Page Hits = %d\n", n - faults);

    return 0;
}