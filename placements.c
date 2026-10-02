#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_mastermind.h"

struct t_result placements(char *usercode, char *truecode){
    struct t_result r;
    int well_placed_pieces = 0;
    int misplaced_pieces = 0;
    int used[4] = {0};
    for (int i = 0; i < 4; i++){
        if (usercode[i] == truecode[i]){
            well_placed_pieces++;
            used[i] = 1;
        }

    }

    for (int j = 0; j < 4; j++){ 
        if (usercode[j] != truecode[j]){
            for (int k = 0; k < 4; k++){
                if(truecode[k] == usercode[j] && used[k] == 0){
                misplaced_pieces++; 
                used[k] = 1;
                break;               
                }
            }
        }
    }

    r.well_placed_pieces = well_placed_pieces;
    r.misplaced_pieces = misplaced_pieces;
    return r;  
}