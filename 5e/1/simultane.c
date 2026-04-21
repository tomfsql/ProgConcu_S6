#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
 pid_t fils = fork();
    if (fils == 0)
    {
        int error = execlp("ls","ls","-l","/usr/share","&","ls","-l","&","ps",NULL);
        if (error == -1)
        {
            perror("exec fail");
            exit(-1);
        }
/*         pid_t fils=fork();
        int error2 = execlp("ls","ls","-l","&",NULL);

        pid_t fils2= fork();
        int error3 = execlp("ps","ps",NULL); */
 }
 wait(NULL);
 return 0;
}
