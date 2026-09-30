#include<stdio.h>
#include<unistd.h>

int main(){

    printf("\nBefore exec\n");

    execl("/bin/ls", "/ls", NULL);

    printf("\nAfter exec\n");

    return 0;
}