#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#define N 10
int main()
{
    int genfiltre[2];
    int filtrepair[2];
    int filtreimpair[2];
    int pairgene[2];
    int impairgene[2];
    int first = pipe(genfiltre);
    int second = pipe(filtrepair);
    int third = pipe(filtreimpair);
    int fourth = pipe(pairgene);
    int fifth = pipe(impairgene);
    int end = -1;
    if (first == -1 || second == -1 || third == -1 || fourth == -1 || fifth == -1)
    {
        perror("Création Pipe");
        exit(-1);
    }
    // getting the sum back
    if (fork() == 0)
    {
        close(genfiltre[1]);
        close(filtrepair[0]);
        close(filtreimpair[0]);
        close(pairgene[1]);
        close(pairgene[0]);
        close(impairgene[1]);
        close(impairgene[0]);
        int readNumber = 0;
        // reading data at the end of the first tube and sending it to the appropriate one
        while (read(genfiltre[0], &readNumber, sizeof(int)) > 0)
        {
            if (readNumber == -1)
            {
                break;
            }
            if (readNumber % 2 == 0)
            {
                write(filtrepair[1], &readNumber, sizeof(int));
                printf("Nombre pair reçu : %d \n", readNumber);
            }
            else
            {
                write(filtreimpair[1], &readNumber, sizeof(int));
                printf("Nombre impair reçu : %d \n", readNumber);
            }
        }
        write(filtrepair[1], &end, sizeof(int));
        write(filtreimpair[1], &end, sizeof(int));
        close(filtreimpair[1]);
        close(filtrepair[1]);
        close(genfiltre[0]);
        exit(0);
    }
    if (fork() == 0)
    {
        close(genfiltre[1]);
        close(genfiltre[0]);
        close(filtrepair[1]);
        close(filtreimpair[1]);
        close(filtreimpair[0]);
        close(pairgene[0]);
        close(impairgene[1]);
        close(impairgene[0]);
        // sum of even numbers
        int readEvenNumber = 0;
        int sum = 0;
        // reading data at the end of the first tube and sending it to the appropriate one
        while (read(filtrepair[0], &readEvenNumber, sizeof(int)) > 0)
        {
            sum += readEvenNumber;
        }
        write(pairgene[1], &sum, sizeof(int));
        close(pairgene[1]);
        close(filtrepair[0]);
        exit(0);
    }
    if (fork() == 0)
    {
        close(genfiltre[1]);
        close(genfiltre[0]);
        close(filtrepair[1]);
        close(filtrepair[0]);
        close(filtreimpair[1]);
        close(pairgene[0]);
        close(pairgene[1]);
        // suming odd numbers
        int readOddNumber = 0;
        int sum = 0;
        while (read(filtreimpair[0], &readOddNumber, sizeof(int)) > 0)
        {
            sum += readOddNumber;
        }
        write(impairgene[1], &sum, sizeof(int));
        close(impairgene[1]);
        close(filtreimpair[0]);
        exit(0);
    }
    close(genfiltre[0]);
    close(filtrepair[0]);
    close(filtreimpair[0]);
    close(filtrepair[1]);
    close(filtreimpair[1]);
    close(pairgene[1]);
    close(pairgene[1]);
    close(impairgene[1]);
    for (int i = 0; i < N; i++)
    {
        int number = rand() % 10 + 1;
        printf("Nombre envoyé : %d \n", number);
        write(genfiltre[1], &number, sizeof(int));
    }
    write(genfiltre[1], &end, sizeof(int));
    close(genfiltre[1]);
    // sending numbers into the pipeline using the first tube

    int oddSum = 0;
    int evenSum = 0;
    read(pairgene[0], &evenSum, sizeof(int));
    printf("Somme des nombres pairs envoyes : %d \n", evenSum);
    read(impairgene[0], &oddSum, sizeof(int));
    printf("Somme des nombres impairs envoyes : %d \n", oddSum);
    close(pairgene[0]);
    close(impairgene[0]);
    for (int i = 0; i < 3; i++)
        wait(NULL);
    return 0;
}