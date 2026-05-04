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
#define SIZE 3
#define N 5

int main()
{
    srand(getpid());
    int shmid = shmget(KEY, SIZE * sizeof(int), 0);
    int mutexId = sem_get(KEY);
    int semId = sem_get(KEY_2);
    int *mem = shmat(shmid, NULL, 0);
    int keep = 1;
    int count = 0;
    while (keep && count < N)
    {
        P(mutexId);
        P(semId);
        if (mem[0] > mem[1])
        {
            int tempmin = mem[1];
            mem[1] = mem[0];
            mem[0] = tempmin;
        }
        else
        {
            mem[2] = -1;
            keep = 0;
        }
        V(mutexId);
        V(semId);
    }
    shmdt(mem);
    return 0;
}