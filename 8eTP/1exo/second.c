#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int num = rand() % 5 + 1;
    printf("Waiting for %d seconds \n", num);
    sleep(num);
    printf("Terminating \n");
    return 0;
}