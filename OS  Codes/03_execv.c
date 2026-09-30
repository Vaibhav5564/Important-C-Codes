#include<stdio.h>
#include<unistd.h>

int main(){

    char *args[] = {"ls", "-l", NULL};
    
    printf("Before execv");

    execv("/bins/ls", args);

    printf("After execv");

    return 0;
}