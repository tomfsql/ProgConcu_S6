#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>

struct threadRet {
    int retour;
};

struct threadArg {
    int number;
    int sleepTime;
};

void* goToSleep(void* arg){
    const struct threadArg* arguments = arg;
    printf("Thread n° %d sleeping for %d seconds \n", arguments->number, arguments->sleepTime);
    sleep(arguments->sleepTime);
    puts("Going back \n");
    return 0;
}

int main(int argc, char* argv[]){
    int n = 0;
    if (argc != 2){
        perror("Missing arguments \n");
        exit(1);
    }
    n = atoi(argv[1]);
    sem_t sem;
    sem_init(&sem,0,0);
    for(int i = 0;i<n;i++){
        pthread_t thread;
        srand(time(NULL));
        int duration = (rand() % 4)+2;
        struct threadArg args;
        args.number = i;
        args.sleepTime = duration;
        pthread_create(&thread,NULL,goToSleep,&args);
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<n;k++){
            if(j != k){
                sem_post(&sem);
            }
        }
        for(int l=1;l<n;l++){
            if(j != l){
                sem_wait(&sem);
            }
        }
    }

    return 0;
}