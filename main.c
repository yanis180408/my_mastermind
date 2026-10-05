#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "my_mastermind.h"

int main(int argc, char *argv[]){
  char *codedemymastermind = NULL;
  int attemps = 10;
  char buffer[6];
  int flag = 0;
  int ended = 0;

  for (int i = 1; i < argc; i++) {
    if(argv[i][0] != '-'){
        continue;
    }
    // printf("gtr%s\n", argv[i]);
      if (strcmp(argv[i], "-c") == 0){
          if (i + 1 < argc && is_valid_code(argv[i + 1])){
              codedemymastermind = argv[i + 1];
            } else {
                printf("Wrong code, expected code of 4 numbers between 0 and 8 included\n");
                return -1;
            }
        } else if (strcmp(argv[i], "-t") == 0){
            if (i + 1 < argc){
                attemps = atoi(argv[i + 1]);
                if (attemps <= 0){
                    printf("Wrong amount of attemps, the number of attemps should be a positive number\n");
                    return -1;
                }
            }
        } else {
            printf("Invalid parametre: %s\nTry with a -c or -t\n", argv[i]);
            return -1;
        }
    }
    
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

  if (codedemymastermind == NULL){
    codedemymastermind = generate_code();
    if (codedemymastermind == NULL){
      return 1;
    }
    flag = 1;
  }
  // printf("code:%s\n", codedemymastermind);
  for (int j = 0; j < attemps; j++){
    printf("---\n");
    printf("Round %d\n", j);
    int n = 0;

    while (1){
      printf(">");
      fflush(stdout);
      n = read(0, buffer, 5);

    //   if (n <= 0){
    //     ended = 1;
    //     break;
    //   }
        int had_newline = 0;
        if (n > 0){
            int had_newline = (buffer[n - 1] == '\n');
      
            if (had_newline){
                n--;
            }            
        }
        else{
            free(codedemymastermind);
            return 0; 
        }

      buffer[n] = '\0';

      if (is_valid_code(buffer) == 1){
        break;
      }

      printf("Wrong input!\n");

      if (!had_newline){
        char c;
        int r = read(0, &c, 1);
        while (r > 0 && c != '\n'){
          r = read(0, &c, 1);
        }
        if (r <= 0){
          ended = 1;
          break;
        }
      }
    }

    if (ended == 1){
      break;
    }

    struct t_result r = placements(buffer, codedemymastermind);

    if (r.well_placed_pieces == 4){
      printf("Congratz! You did it!\n");
      break;
    }
    else{
      printf("Well placed pieces: %d\n", r.well_placed_pieces);
      printf("Misplaced pieces: %d\n", r.misplaced_pieces);
    }
  }

  if (flag != 0){
    free(codedemymastermind);
  }


  return 0;
}
