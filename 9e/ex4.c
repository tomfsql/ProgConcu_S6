#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    __pid_t pid_fils = fork();
    if(pid_fils == 0){
        pid_fils = getpid();
        printf("Processus enfant de PID %d créé \n", getpid());
        while(1){
            sleep(1);
            puts("Le processus enfant tourne \n");
        }
    }
    for(int i=0;i<3;i++){
        sleep(1);
        printf("Le processus parent tourne depuis %d s \n", i);
    }
    puts("Terminaison du processus enfant déclenchée");
    kill(pid_fils, SIGTERM);
}