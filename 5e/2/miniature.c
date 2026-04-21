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
 }
 wait(NULL);
 return 0;
}
