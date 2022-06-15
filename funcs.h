#include <stdio.h>
#include <stdlib.h>

extern int winner, count, entry, sign, player, oob, taken;
extern char pos[10];

void win();
void renderBoard();
void checkWinner();
void checkPlayer();
void titleLine();
void askForChoice();

// colors
void colorCheck(int cell);
void p1Red();
void p2Blue();
void resetColor();

