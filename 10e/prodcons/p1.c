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
    int *tab[N];
    for (int j = 0; j < N; j++)
    {
        *tab[j] = rand() % 5;
    }
    int max = *tab[0];
    int offset = 1;
    int position = 0;
    while (offset < N)
    {
        if (*tab[offset] > max)
        {
            max = *tab[offset];
            position = offset;
        }
        offset++;
    }
    int mutexId = sem_get(KEY);
    int semId = sem_get(KEY_2);
    P(semId);
    P(mutexId);
    mem[0] = max;
    V(mutexId);
    V(semId);

    P(semId);
    P(mutexId);
    if (mem[2] != -1)
    {
        *tab[position] = mem[0];
    }
    else
    {
        for (int j = 0; j < N; j++)
        {
            printf(" %d \n ", *tab[j]);
        }
    }
    shmdt(mem);
    return 0;
}