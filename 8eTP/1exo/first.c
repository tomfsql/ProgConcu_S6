#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dijkstra.h"

int main(){
    key_t keyFirst = 130;
    sem_create(keyFirst, 1);
    int firstId = sem_get(keyFirst);
    srand(time(NULL));
    int num = 3 + rand() % 3;
    printf("Waiting for %d seconds \n", num);
    P(firstId);
    sleep(num);
    printf("Terminating \n");
    sem_delete(firstId);
    return 0;
}