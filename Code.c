#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check for a win
int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

// Function to check if the board is full (draw)
int checkDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0; // Board is not full yet
    return 1; // It's a draw
}

// Function to make a move
int makeMove(int player, int choice) {
    char mark = (player == 1) ? 'X' : 'O';

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == choice + '0') { 
                board[i][j] = mark;
                return 1;
            }
        }
    }
    return 0; 
}

int main() {
    int player = 1, choice, validMove;
    
    while (1) {
        displayBoard();
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &choice);

        validMove = makeMove(player, choice);
        if (!validMove) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        if (checkWin()) {
            displayBoard();
            printf("Player %d wins!\n", player);
            break;
        }

        if (checkDraw()) {
            displayBoard();
            printf("It's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1; 
    }

    return 0;
}
