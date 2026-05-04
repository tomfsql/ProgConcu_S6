#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void redirect(int signum)
{
    if (signum == SIGUSR1)
    {
        puts("Received signal SIGUSR1 \n");
    }
    if (signum == SIGUSR2)
    {
        puts("Received signal SIGUSR1, terminating \n");
        exit(0);
    }
}

int main(void)
{
    __pid_t pid_fils = fork();
    if (pid_fils == -1)
    {
        perror("Fork");
    }
    if (pid_fils == 0)
    {
        struct sigaction act;
        memset(&act, 0, sizeof(act));
        act.sa_handler = redirect;
        sigaction(SIGUSR1, &act, NULL);
        sigaction(SIGUSR2, &act, NULL);
        pid_fils = getpid();
        printf("Processus enfant de PID %d créé \n", getpid());
        while (1)
        {
            pause();
        }
    }
    else
    {
        for (int i = 1; i < 6; i++)
        {
            sleep(1);
            printf("Le processus parent tourne : %d \n", i);
            if (i == 3)
            {
                printf("Déclenchement de l'affichage du fils sur le compte %d \n", i);
                kill(pid_fils, SIGUSR1);
            }
            if (i == 5)
            {
                printf("Déclenchement de la terminaison du fils sur le compte %d \n", i);
                kill(pid_fils, SIGUSR2);
            }
        }
    }
    return 0;
}