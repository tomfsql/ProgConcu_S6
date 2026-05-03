#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"


int main(){
    // création d'un sémaphore avec 2 jetons
    sem_create(130, 0);
    sem_create(131,0);
    return 0;
}