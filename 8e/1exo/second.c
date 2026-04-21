#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "dijkstra.h"

int main(){
    int id = sem_get(130);
    srand(time(NULL));
    printf("J'attends \n");
    P(id);
    int num = rand() % 5 + 1;
    printf("Waiting for %d seconds \n", num);
    sleep(num);
    printf("Terminating \n");
    return 0;
}