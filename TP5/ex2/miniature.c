#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv)
{
 if (argc > 1){
    int exec = execv(argv[1], NULL);
 }
 wait(NULL);
 return 0;
}
