#include <stdio.h>
#include <unistd.h>

int main(){
    int cpt = 0;
    while(cpt < 3){
        __pid_t pid_fils = fork();
        if(pid_fils == 0){
            printf("Compteur de boucle : %d, ", cpt);
            printf("Valeur de retour : %d \n", pid_fils);
            printf("PID enfant %d,", getpid());
            printf("PID parent %d \n", getppid());
        }
        cpt++;
    }
}