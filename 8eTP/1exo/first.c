#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dijkstra.h"

int main(){
    srand(time(NULL));
    int num = 3 + rand() % 3;
    printf("Waiting for %d seconds \n", num);
    sleep(num);
    printf("Terminating \n");
    return 0;
}