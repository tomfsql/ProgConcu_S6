#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int N = 3;

int* count[N-1] = {0};

void count_numbers(char* tab, int* count){
    for (int i = 0; i < len(tab); i++){
        count[(int)(tab[i]+1)] = count[(int)(tab[i]+1)]++;
    }
}

void update_tab(char* tab, int* count){
    int size = len(tab) + len(count);
    char* newtab = malloc(size * sizeof(char));
}

void display(int input){
    if (input % 2 == 0) return 0;
    for(int i = input-1; i > 1; i--){
        if (input % i == 0) return 0;
    }
    return 1;
}

int find_first_prime_div(int input){
    if (input % 2 == 0) return 2;
    int fpd = input;
    int current = 3;
    while (current < input && (is_prime(current)==1)){
        if(input % current == 0){
            fpd = current;
        }
        current++;
    }
    return fpd;
}
int main(){
    int input = 0;
    printf("Entrez un nombre : ");
    scanf("%d", &input);
    int output = input;
    while(output != 1){
        int div = find_first_prime_div(output);
        printf("\nPremier diviseur : %d", div);
        output = output/div;
        printf("\nOutput : %d \n", output);
    }
    return 0;
    //printf("\nPlus petit diviseur de %d obtenu : %d \n", input, result);
}