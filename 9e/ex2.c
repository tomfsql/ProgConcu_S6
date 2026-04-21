#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
struct sigaction act;

int main(void)
{
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    sigaction(SIGINT,&act,NULL);
    while(1){
        printf("Background task");
    }
}