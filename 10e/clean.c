#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"
#include <sys/wait.h>
#include <sys/shm.h>



int main(){
    int shmid = shmget(130,1 * sizeof(int),0);
    int res = shmctl(shmid,IPC_RMID,NULL);
    if (res == -1) {
        perror("Delete Shm");
    }
    int mutexId = sem_get(130);
    sem_delete(mutexId);
}