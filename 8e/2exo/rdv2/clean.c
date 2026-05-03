#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"


int main(){
    sem_delete(sem_get(130));
    sem_delete(sem_get(131));
    return 0;
}