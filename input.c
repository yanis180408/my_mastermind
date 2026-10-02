#include <unistd.h>
#include "my_mastermind.h"

int my_readline(char *buffer){
    int count = 0;
    char c;

    while (1){

        int x = read (0, &c, 1);

        if (x == 0 || x == -1){
            return -1;
        }

        else if (c == '\n'){

            if (count <= 4){
                buffer[count] = '\0';
            }

            else{
                buffer[5] = '\0';
            }

            if (count == 4){
                return 0;

            }
            else{
                return 1;

            }
        }
        else{
            if (count < 4){
                buffer[count] = c;
            }

            count++;

        }

    }

}