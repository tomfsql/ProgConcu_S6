#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

struct structArg
{
    pthread_barrier_t *barrier;
    int id;
};
void *task1(void *arg)
{
    struct structArg *args = arg;
    srand(getpid() + args->id);
    int random = (rand() % 3) * args->id;
    printf("Thread %d sleeping %d\n", args->id, random);
    sleep(random);
    printf("Thread %d wait others\n", args->id);
    pthread_barrier_wait(args->barrier);
    printf("Thread %d awake\n", args->id);
    return NULL;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Missing argument");
    }
    int value = atoi(argv[1]);
    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, NULL, value);
    pthread_t thread[value];
    struct structArg args[value];
    for (int i = 0; i < value; i++)
    {
        args[i].barrier = &barrier;
        args[i].id = i + 1;
        pthread_create(&thread[i], NULL, task1, &args[i]);
    }
    for (int i = 0; i < value; i++)
    {
        pthread_join(thread[i], NULL);
    }
    pthread_barrier_destroy(&barrier);
    return 0;
}