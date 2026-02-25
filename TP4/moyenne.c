#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int convert(char* input){
    int value = 0;
    int convert = sscanf(input, "%d", &value);
    if (convert != 1){
        printf("Wrong arg \n");
        return -1;
    }
    return value;
}

int main(int argc, char* argv[]){
    if (argc < 2) printf("Impossible de calculer \n");
    else{
        int count = 0;
        int sum = 0;
        for(int k = 1;k<argc;k++){
            int val = convert(argv[k]);
            if(val != -1){
                count++;
                sum+=val;
            }
            else{
                return -1;
            }
            if(count != 0){
                sum/=count;
            }
            else{
                printf("Division par zéro");
            }
        }
        printf("%d \n", sum);
    }
    return 0;
}