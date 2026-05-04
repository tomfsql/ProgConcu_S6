#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>

struct structArg
{
    pthread_mutex_t *mutex;
    sem_t sem;
    int count;
    int N;
};

void *task1(void *arg)
{
    struct structArg *a = (struct structArg *)arg;

    pthread_mutex_lock(a->mutex);
    a->count++;

    if (a->count == a->N)
    {
        for (int i = 0; i < a->N; i++)
        {
            sem_post(&a->sem);
        }
    }
    pthread_mutex_unlock(a->mutex);

    srand(time(NULL) + pthread_self());
    printf("Processus %d en attente au point de rendez-vous...\n", a->count);
    sleep(rand() % 3); // Simulate some work with a random sleep

    printf("thread num %d à terminer\n", a->count);
    sem_wait(&a->sem);

    return NULL;
}

int main(int argc, char *argv[])
{

    struct structArg args;
    int N = atoi(argv[1]);
    pthread_t thread[N];
    pthread_mutex_t mutex;

    sem_init(&args.sem, 0, 0);

    args.count = 0;
    args.N = N;
    args.mutex = &mutex;

    pthread_mutex_init(args.mutex, NULL);

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <N>  \r\n", argv[0]);
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {

        pthread_create(&thread[i], NULL, task1, &args);
        // printf("interation num : %d\n",i);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);

    puts("Tout le monde est là ! Libération des processus.\n");
}