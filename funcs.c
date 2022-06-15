#include "funcs.h"

int winner = 0, count = 0, entry, sign, player, oob, taken;

char pos[10] = {'0', '1', '2', '3', '4' ,'5' ,'6' ,'7' ,'8' ,'9'};

void win() {
    renderBoard();

    if (winner == 1 && player == 1) {
        p1Red();
        printf("Player %d is the winner!\n", player);
        resetColor();
    }
    else if (winner == 1 && player == 2){
        p2Blue();
        printf("Player %d is the winner!\n", player);
        resetColor();
    }
}



void renderBoard() {
    system("clear");
    titleLine();
        printf("   |   |  \n");
        colorCheck(7);
        printf("|");
        colorCheck(8);
        printf("|");
        colorCheck(9);
        printf("\n___|___|___\n"
               "   |   | \n");
        colorCheck(4);
        printf("|");
        colorCheck(5);
        printf("|");
        colorCheck(6);
        printf("\n___|___|___\n"
               "   |   | \n");
        colorCheck(1);
        printf("|");
        colorCheck(2);
        printf("|");
        colorCheck(3);
        
        printf("\n   |   |  \n");

        if (oob == 1) {
            printf("Selection is out of bounds!\n");
            oob = 0;
        }
        
        if (taken == 1) {
            printf("This selection is already taken\n");
            taken = 0;
        }
}

void askForChoice(){
    if (player == 1){
            p1Red();
            printf("Move for player %d (1-9): ", player);
            resetColor();
        }
        else if (player == 2){
            p2Blue();
            printf("Move for player %d (1-9): ", player);
            resetColor();
        }
}

void checkWinner() {
    if ((pos[1] == pos[5] && pos[5] == pos[9]) || (pos[3] == pos[5] && pos[5] == pos[7])) {
            winner = 1;
            win();
    }
    else if ((pos[1] == pos[2] && pos[2] == pos[3])) {
            winner = 1;
            win();
    }
    else if ((pos[4] == pos[5] && pos[5] == pos[6])) {
            winner = 1;
            win();
    }
    else if ((pos[7] == pos[8] && pos[8] == pos[9])) {
            winner = 1;
            win();
    }
    else if ((pos[1] == pos[4] && pos[4] == pos[7])) {
            winner = 1;
            win();
    }
    else if ((pos[2] == pos[5] && pos[5] == pos[8])) {
            winner = 1;
            win();
    }
    else if ((pos[3] == pos[6] && pos[6] == pos[9])) {
            winner = 1;
            win();
    }
    
}

void checkPlayer() {
    player = (count % 2) ? 2:1;
    sign = (player == 1) ? 'X' : 'O';
}

void colorCheck(int cell) {
    if (pos[cell] == 'X') {
        p1Red();
        printf(" %c ", pos[cell]);
    }
    else if (pos[cell] == 'O') {
        p2Blue();
        printf(" %c ", pos[cell]);
    }
    else {
        printf("\033[0m %c ", pos[cell]);
    }
    resetColor();
}

void p1Red() {
    printf("\033[0;31m");
}

void p2Blue() {
    printf("\033[0;36m");
}

void resetColor(){
    printf("\033[0m");
}

void titleLine() {
    printf("TicTacToe\n");
    p1Red();
    printf("Player 1 (X)");
    resetColor();
    printf(" --- ");
    p2Blue();
    printf("Player 2 (O)");
    printf("\n\n");
    resetColor();
}