#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dijkstra.h"

int main(){
    int first = sem_get(130);
    int second = sem_get(131);
    int third = sem_get(132);
    srand(time(NULL));
    int num = 3 + rand() % 3;
    printf("Waiting for %d seconds \n", num);
    sleep(num);
    printf("Rendez-vous rejoint par le processus de pid %d \n", getpid());
    V(third);
    V(third);
    P(first);
    P(second);
    printf("Terminating \n");
    return 0;
}