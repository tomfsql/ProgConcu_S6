#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int status_fils = 0;
    int step = 50;
    for(int i=0; i<4;i++){
        pid_t fils = fork();
        if(fils == 0){
            int start = i * step;
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
    }
    return 0;
}