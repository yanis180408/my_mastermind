#ifndef my_mastermind_h
#define my_mastermind_h

int is_valid_code(char *codedemymastermind);

int my_strlen(char *str);

struct t_result {
int well_placed_pieces;
int misplaced_pieces;
};

struct t_result placements(char *usercode, char *truecode);

int my_readline(char *buffer);

char *generate_code(void);

#endif
