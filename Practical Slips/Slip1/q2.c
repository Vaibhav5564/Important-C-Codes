#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char cmd[100], *a[10];
    int i, ch, count;
    FILE *fp;

    while(1)
    {
        printf("$ ");
        fgets(cmd, 100, stdin);

        i = 0;
        a[i] = strtok(cmd, " ");

        while(a[i] != NULL)
            a[++i] = strtok(NULL, " ");

        if(strcmp(a[0], "exit\n") == 0)
            break;

        if(strcmp(a[0], "count") == 0)
        {
            fp = fopen(a[2], "r");
            count = 0;

            while((ch = fgetc(fp)) != EOF)
            {
                if(a[1][0] == 'c')
                    count++;

                else if(a[1][0] == 'l' && ch == '\n')
                    count++;

                else if(a[1][0] == 'w' &&
                       (ch == ' ' || ch == '\n'))
                    count++;
            }

            printf("%d\n", count);
            fclose(fp);
        }
        else
        {
            if(fork() == 0)
                execvp(a[0], a);
            else
                wait(NULL);
        }
    }

    return 0;
}