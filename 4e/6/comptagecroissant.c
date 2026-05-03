#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int step = 50;
        int status_fils = 0;

    for(int i=0; i<4;i++){
        pid_t fils = fork();
        if(fils == 0){
            int start = i * step +1;
            int end = start + step;
            printf("Je vais compter de %d à %d fork a retourné %d\n",start,end,getpid());
            int j = start;
            while(j < end){
                printf("%d \n", j);
                j++;
            }
            exit(i);
        }
        else if(fils < 0){
            perror("Fork error ");
        }
        else{
            wait(&status_fils);
        }
    }
    for(int i=0;i<4;i++){
        pid_t fils = wait(&status_fils);
        printf("fils: %d, status: %d\n",fils, WEXITSTATUS(status_fils));
    }
    return 0;
}