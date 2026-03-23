#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int tube1[2];
    int tube2[2];
    int tube3[2];
    int first = pipe(tube1);
    int second = pipe(tube2);
    int third = pipe(tube3);
    if (first == -1 || second == -1 || third == -1) {
        perror("Création Pipe");
        exit(-1);
    }
    if (fork() == 0){
        close(tube1[0]);
        dup2(tube1[1],1);
        close(tube1[1]);
        close(tube2[0]);
        close(tube2[1]);
        close(tube3[1]);
        close(tube3[0]);
        execlp("cat","cat","/etc/passwd",NULL);
        // pipeline input
    }
    if (fork() == 0) {
        close(tube1[1]);
        close(tube2[0]);
        dup2(tube1[0],0);
        dup2(tube2[1],1);
        close(tube2[1]);
        close(tube1[0]);
        close(tube3[1]);
        close(tube3[0]);
        execlp("cut", "cut", "-f", "1,3", "-d",":", NULL);
        // first part of the pipeline
    }
    if (fork() == 0) {
        close(tube1[1]);
        dup2(tube2[0],0);
        dup2(tube3[1],1);
        close(tube2[0]);
        close(tube1[0]);
        close(tube2[1]);
        close(tube3[1]);
        close(tube3[0]);
        execlp("sed", "sed","s+^\\(.*\\):\\(.*\\)+\\2:\\1+", NULL);
        // second part of the pipeline
    }
    if (fork() == 0) {
        close(tube1[1]);
        close(tube1[0]);
        dup2(tube3[0],0);
        close(tube3[0]);
        close(tube3[1]);
        close(tube2[0]);
        close(tube2[1]);
        execlp("sort", "sort", "-n",NULL);
        // third part of the pipeline
    }
    else{
        close(tube1[0]);
        close(tube1[1]);
        close(tube2[0]);
        close(tube2[1]);
        close(tube3[0]);
        close(tube3[1]);
    }
    return 0;
}