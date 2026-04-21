#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* invert(char* input){
    int size = strlen(input);
    char* output = malloc(size+1 * sizeof(char));
    for(int i=0;i<size;i++){
        output[i] = input[size-i-1];
    };
    output[size] = '\0';
    return output;
}

int main(int argc, char* argv[]){
    if (argc < 2) printf("Missing arg or args \n");
    else{
        int totalsize  = 0;
        for (int i=1;i < argc; i++){
            totalsize+=strlen(argv[i]);
            totalsize++;
        }
        char* output = malloc(totalsize * sizeof(char));
        char* first = invert(argv[1]);
        int first_len = strlen(argv[1]);
        int offset = 0;
        while (offset<first_len){
            output[offset]=first[offset];
            offset++;
        }
        output[offset++] = ' ';
        for(int k = 2;k<argc;k++){
            strcat(output, invert(argv[k]));
            offset+=strlen(argv[k]);
            output[offset++] = ' ';
        }
        output[totalsize] = '\0';
        printf("%s \n", output);
        free(output);
    }
    return 0;
}