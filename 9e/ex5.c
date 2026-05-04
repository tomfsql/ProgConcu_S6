#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act;

void redirect(int signum)
{
    if (signum == SIGINT)
    {
        puts("Received signal SIGINT \n");
        // puts("end");
        //_exit(0);
    }
}

int main(void)
{
    __pid_t pid_fils = fork();
    if (pid_fils == 0)
    {
        memset(&act, 0, sizeof(act));
        act.sa_handler = redirect;
        sigaction(SIGINT, &act, NULL);
        pid_fils = getpid();
        printf("Processus enfant de PID %d créé \n", getpid());
        while (1)
        {
            sleep(1);
            puts("Le processus enfant tourne \n");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf("Le processus parent tourne depuis %d s \n", i);
    }
    puts("Terminaison du processus enfant déclenchée");
    return 0;
}

// on constate que lorsqu'on utilise Ctrl C, le père s'arrête mais pas le fils
// qui a son handler propre et garde sa diffusion