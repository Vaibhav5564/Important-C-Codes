#include<stdio.h>
#include<unistd.h>

int main(){
    char *args[] = {"ls", "-l", NULL};

    printf("\nBefore execvp\n");

    execvp("ls", args);

    printf("\nAfter Execution");
}