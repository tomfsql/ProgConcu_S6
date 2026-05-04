#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dijkstra.h"

int main(int argc, char *argv[]){
    int id = sem_get(130);
    int value = 0;
    if(argc > 1){ value = atoi(argv[1]); }
    else{
        perror("Missing value \n");
    }
    return 0;
}