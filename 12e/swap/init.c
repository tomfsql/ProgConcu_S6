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
    sem_create(KEY, 1);
    sem_create(KEY_2, 0);
    int shmid = shmget(KEY, SIZE * sizeof(int),
                       IPC_CREAT | IPC_EXCL | 0600);
    if (shmid == -1)
    {
        perror("Shmget Memory");
    }
    return 0;
}