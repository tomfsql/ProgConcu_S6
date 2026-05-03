#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "dijkstra.h"

int main(){
    int first = sem_get(130);
    int second = sem_get(131);
    srand(time(NULL));
    int num = 3 + rand() % 3;
    printf("Waiting for %d seconds \n", num);
    sleep(num);
    printf("Rendez-vous rejoint par le second processus de pid %d \n", getpid());
    V(second);
    P(first);
    printf("Terminating \n");
    return 0;
}