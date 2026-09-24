#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
  char *codedemamastermind = NULL;
  int attemps = 10;
  for (int i = 1; i < argc ; i++) { 
    if (strcmp(argv[i], "-c") == 0){
      if (i+1 < argc){
        codedemamastermind = argv[i+1];
      }
    }
    if (strcmp(argv[i], "-t") == 0){
      if (i+1 < argc){
        attemps = atoi (argv[i + 1]);
      }
    }

  }
  return 0;
}



int is_valid_code(){
  
  
}
