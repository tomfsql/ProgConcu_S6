#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
struct sigaction act;

int fin = 0;

void redirect(int signum){
    if(signum == SIGINT){
        printf("Received signal \n");
        fin = 1;
        puts("end");
        _exit(0);
    }
}

int main(void)
{
    int fin = 0;
    memset(&act,0,sizeof(act));
    act.sa_handler = redirect;
    sigaction(SIGINT,&act,NULL);
    while(!fin){
        printf("Background task");
    }
}