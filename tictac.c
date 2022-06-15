#include "funcs.h"

int main() {
    
    while (count < 9 && winner != 1){
    
        //print board
        renderBoard();
        //check which player active
        checkPlayer();
        //ask for input in color of player
        askForChoice();
        //take input
        scanf("%d", &entry);
        //check input is in range and not taken
        if(entry < 1 || entry > 9) {
            oob = 1;
            continue;
        }
        if (pos[entry] == 'X' || pos[entry] =='O') {
            taken = 1;
            continue;
        }

        pos[entry] = sign;
        count++;
        //check if anyone has won
        checkWinner();
        
    }
    //if no winner and moves finished show DRAW
    if (winner != 1){
        printf("Game has ended in a DRAW!\n");
    }

}