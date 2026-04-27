#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc == 1){
        perror("Missing args");
    }
    int total = atoi(argv[1]);
    int cpt = 0;
    int status_fils =0;
    while(cpt < total){
        pid_t fils = fork();
        if (fils != 0)
        {
            cpt++;
            wait(&status_fils);
            break;
        }
    }
    printf("%d\n",WEXITSTATUS(status_fils));
    return 0;
}