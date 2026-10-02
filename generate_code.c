#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_mastermind.h"

char *generate_code(void){

    srand(time(NULL));
    int length = 4;
    char *random_code = malloc(length + 1); //+ 1 c'est pour le '\0'
    int used[9] = {0};
    if (!random_code){
        return NULL;
    }
    int i = 0;
    while(i < length){
        int j = rand() % 9;

        if (used[j] == 0){
            random_code[i] = j + '0';
            used[j] = 1;
            i++;
            } 
        
        }
    random_code[i] = '\0';
    return random_code;
}