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

  printf("Will you find the secret code?\n");
  printf("Please enter a valid guess\n");
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-c") == 0){
      if (i + 1 < argc){
        codedemymastermind = argv[i + 1];
      }
    }
    if (strcmp(argv[i], "-t") == 0){
      if (i + 1 < argc){
        attemps = atoi(argv[i + 1]);
      }
    }
  }

  if (codedemymastermind == NULL){
    codedemymastermind = generate_code();
    if (codedemymastermind == NULL){
      return 1;
    }
    flag = 1;
  }

  for (int j = 0; j < attemps; j++){
    printf("---\n");
    printf("Round %d\n", j);
    int n = 0;

    while (1){
      printf(">");
      n = read(0, buffer, 5);
      if (n <= 0){
        ended = 1;
        break;
      }

      int had_newline = (buffer[n - 1] == '\n');
      if (had_newline){
        n--;
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