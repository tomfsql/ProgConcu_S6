#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
struct sigaction act;

void redirect(int signum){
    if(signum == SIGINT){
        printf("Received signal");
        puts("end");
        _exit(0);
    }
}

int main(void)
{
    memset(&act,0,sizeof(act));
    act.sa_handler = redirect;
    sigaction(SIGINT,&act,NULL);
    while(1){
        printf("Background task");
    }
}