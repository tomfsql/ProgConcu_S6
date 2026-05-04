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
int main()
{
    int shmid = shmget(KEY, SIZE * sizeof(int), 0);
    if (shmid == -1)
    {
        perror("Shmget Memory");
        exit(-1);
    }
    int *mem = shmat(shmid, NULL, 0);
    if ((int64_t)mem == -1)
    {
        perror("Shmat Memory");
        exit(-1);
    }
    int mutexId = sem_get(KEY);
    int semId = sem_get(KEY_2);
    P(semId);
    P(mutexId);
    for (int i = 0; i < SIZE; i++)
    {
        int var = mem[i];
        printf("read: %d\n", var);
    }
    V(mutexId);
    shmdt(mem);
    return 0;
}