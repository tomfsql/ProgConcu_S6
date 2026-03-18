#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
    int requestTube[2];
    int responseTube[2];
    char feedback[5];
    int request =  pipe(requestTube);
    int response = pipe(responseTube);
    int *guess = 0;
    if (request == -1 || response == -1) {
        perror("Création Pipe"); exit(-1);
    }
    if (fork() == 0) {
        close(requestTube[1]);
        close(responseTube[0]);
        srand(time(NULL));
        int random = rand();
        int try = 0;
        read(requestTube[0], &try, sizeof(int));
        close(requestTube[0]);
        printf("Received : %d\n",try);
        if(try == random){
            printf("yes");
            write(responseTube[1],"=",sizeof(char));

        }
        else if(try > random){
            write(responseTube[1],"+",sizeof(char));
        }
        else {
            write(responseTube[1],"-",sizeof(char));
        }
    } else {
        close(requestTube[0]);
        close(responseTube[1]);
        scanf("Entrez un nombre : %d", guess);
        printf("Send guess : %d\n", *guess);
        write(requestTube[1],guess,sizeof(int));
        read(responseTube[0], &feedback, sizeof(int));
        printf("Received : %s ", feedback);
    }
    close(requestTube[1]);
    return 0;
}