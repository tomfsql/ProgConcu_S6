#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "dijkstra.h"
#define KEY 5942
#define KEY_2 5943
#define SIZE 4
int main(void)
{
    int shmid = shmget(KEY, SIZE * sizeof(int), 0);
    int res = shmctl(shmid, IPC_RMID, NULL);
    if (res == -1)
    {
        perror("Delete Shm");
    }
    int mutexId = sem_get(KEY);
    sem_delete(mutexId);
    int semId = sem_get(KEY_2);
    sem_delete(semId);
    return 0;
}