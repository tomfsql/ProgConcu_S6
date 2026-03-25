#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "dijkstra.h"

int main(){
    key_t keySecond = 130;
    sem_create(keySecond, 1);
    int secondId = sem_get(keySecond);
    srand(time(NULL));
    int num = rand() % 5 + 1;
    printf("Waiting for %d seconds \n", num);
    P(secondId);
    sleep(num);
    printf("Terminating \n");
    sem_delete(secondId);
    return 0;
}