#include<stdio.h>
#include<unistd.h>

int main(){
    int pid;
    
    pid = fork();

    if(pid<0) printf("\nProcess Creation Failed");

    else if(pid == 0) printf("\nThis is Child Process");

    else printf("\nThis is Parent Process");

    return 0;
}