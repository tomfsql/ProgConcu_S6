#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include <sys/wait.h>
#include <sys/shm.h>

int main(){
    int shmid = shmget(130,1 * sizeof(int),0);
    if (shmid == -1) {
        perror("Getting Shm");
    }
    return 0;
}