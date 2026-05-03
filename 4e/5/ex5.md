# Programmation Concurrente - TP4 - Fork & Arguments - Exercice 5

## Cas n°1

```c=
#include <sys/types.h>
#include <unistd.h>

 int main(void) {
    int i, n=0;
    pid_t fils_pid;
    for (i=1; i< 5; i++){
        fils_pid = fork();
        if (fils_pid > 0){
            n = i*2;
            break;
        }
    }
    printf("%d\n", n);
    return 0;
 }
```

1. Dans le bloc d'exécution du if ( ligne 12 & 13), on se trouve dans le processure père.
2. Ce programme n'est pas déterministe car l'ordre d'exécution des fils dépend du système.
3. Un affichage possible : 4 6 1 2 8 10
4. Il faut attendre qu'un processus aie fini son fork pour lancer le suivant.
5. L'appel à fork peut échouer si le nombre de processus lancés atteint le plafond du système.
