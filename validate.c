#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_mastermind.h"

int is_valid_code(char *codedemymastermind){
    if (my_strlen(codedemymastermind) != 4){
        return 0;
    } else {
        for (int i = 0; i < 4; i++){
            if (codedemymastermind[i] < '0' || codedemymastermind[i] > '8'){  
                return 0;
            }
        }
    }

    return 1;
}