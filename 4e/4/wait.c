#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int n = 0;
    if (argc != 2){
        perror("Missing arguments \n");
        exit(1);
    }
    int success = sscanf(argv[1],"%d",&n);
    if(!success)
        exit(-2);
    int status_fils = 0;
    for(int i=0; i<n;i++){
        pid_t fils = fork();
        if(fils == 0){
            pid_t pere = getppid();
            pid_t moi = getpid();
            printf("%d - Je suis %d, mon père est %d, fork a retourné %d\n",i,moi,pere,fils);
            sleep(2*i);
            printf("Reprise \n");
            exit(i);
        }
        else if(fils < 0){
            perror("Fork error ");
        }
    }
    for(int i=0;i<n;i++){
        pid_t fils = wait(&status_fils);
        printf("fils: %d, status: %d\n",fils, WEXITSTATUS(status_fils));
    }
    return 0;
}