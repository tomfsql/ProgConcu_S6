#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char* argv)
{
 if (argc > 1){
    char* args[3] = {"cd", argv[1], NULL};
    int exec = execv(args, NULL);
    DIR* directory = opendir(argv[1]);
    struct dirent* entry = readdir(directory);
    // ajouter vérif fichiers et récupération path
    for(int i=0; i<8;i++){
      int step = 5;
        pid_t fils = fork();
        if(fils == 0){
            int start = i * 8 +1;
            int end = start + step;
            printf("Je vais convertir de %d à %d fork a retourné %d\n",start,end,getpid());
            int j = start;
            while(j < end){
                printf("%d \n", j);
                int error = execlp("convert","convert","images/exercice_2/images/","-resize","10%","images/exercice_2/sortie",NULL);
                j++;
            }
            exit(i);
        }
        else if(fils < 0){
            perror("Fork error ");
        }
    }
 }
 wait(NULL);
 return 0;
}
