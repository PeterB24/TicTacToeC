#include <stdio.h>
#include <stdbool.h>

/*declaring universal varibles*/
char positionBoard[3][3]; // Labels positions 1 - 8
char Board[3][3]; //The 3 by 3 Array in which the game is played


/*function prototype*/
void initializeBoard();
void initializePosition();
void displayBoard(); //displays positon board at the start
bool checkWinner();
bool checkLoser();
bool checkFullBoard();
void makeMove(); //Plays game
void printBoard(); //Prints game board

int main() {
char x;
bool y = false;
while(!y) {
    /*These first four functions start the game by initalizing both boards, displays the position for the user and starts the game*/ 
    initializePosition();
    initializeBoard();
    displayBoard();
    makeMove();
 
    //If the board is not full or no winner the games continue
    while(!(checkWinner() || checkFullBoard() || checkLoser())) {
        makeMove();
        checkWinner(); 
        checkLoser();
        checkFullBoard();
    }
        if(checkWinner()) {
            printf("Winner!\n");
        }
        else if(checkLoser()) {
            printf("Loser!\n");
        }
        else {
            printf("Draw!\n");
        }
    
        while(!(x == 'Y' || x == 'N')) {
            printf("Would you like to play again (Y/N): ");
            scanf("%c", &x);
            
            if(x == 'Y' || x == 'N') {
                if(x == 'N') {
                    y = true;
                }
            }
        }
    }
    
        
    return 0;
}

//assigning values 0 - 8 in their repected locations
void initializePosition() {
    int i, j;
    char x = '0';

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            positionBoard[i][j] = x;
            x = x + 1;
        }

    }
}

void initializeBoard() {
    int i, j;
    //Set all postions on Board to NULL
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++){
            Board[i][j] == ' ';
        }
    }
}

void displayBoard() {
    int i, j, x;
    printf("\n\n");
    //Prints out postion board
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            printf(" %c |", positionBoard[i][j]);
        }
        printf(" %c", positionBoard[i][j]);
        if(i < 2) {
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

void printBoard() {
    int i, j;
    //prints current Board
    printf("\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            printf(" %c |", Board[i][j]);
        }
        printf(" %c\n", Board[i][j]);
        if(i < 2) {
            printf("-----------\n");
        }
    }
}

void makeMove() {
    char x; //The postion the user inputs
    bool y = false; //bool used for input loop
    int i, j, checkRow, checkCol;
    int row = rand() % 3; //RNG for apponent's placement
    int col = rand() % 3;
    
    while(!y) {
        printf("Please Enter a position: ");
        scanf("%c", &x); //scans postion on board
    
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                //finding postion with to i & j
                if(positionBoard[i][j] == x) {
                    if(Board[i][j] != 'O' && Board[i][j] != 'X') {
                        //assigning 'O' to that location
                        Board[i][j] = 'O';
                        //stores postion for apponent
                        checkRow = i;
                        checkCol = j;
                        //to exit loop
                        y = true;
                    }
                    else {
                        printf("Invalid postion, Try again\n");
                    }
                }
            }
        }
    }
    
    if(!(checkFullBoard())) {
    /*insuring that the position the computer choose is not taken up*/
        if((row == checkRow && col == checkCol) || (Board[row][col] == 'O' || Board[row][col] == 'X')) {
            while(Board[row][col] == 'O' || Board[row][col] == 'X') {
                    //changing numbers until its on a blank space
                    row = rand() % 3;
                    col = rand() % 3;
                }
            //assigns 'X' to that location
            Board[row][col] = 'X';
        }
        else {
            Board[row][col] = 'X';
        }
    }
    else {
        checkWinner();
        checkLoser();
    }

    //prints board to show new standings
    printBoard();
}

bool checkWinner() {
    int i;
    //Check row
    for(i = 0; i < 3; i++) {
        if(Board[i][0] == 'O' && Board[i][1] == 'O' && Board[i][2] == 'O') {
            return true;
        }
    }
    
    //Check column
    for(i = 0; i < 3; i++) {
        if(Board[0][i] == 'O' && Board[1][i] == 'O' && Board[2][i] == 'O') {
            return true;
        }
    }
    
    //Check diagnol
    if(Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O') {
        return true;
    }
    if(Board[0][2] == 'O' && Board[1][1] == 'O' && Board[2][0] == 'O') {
        return true;
    }
    
    return false;
}

bool checkLoser() {
    int i;
    //Check row
    for(i = 0; i < 3; i++) {
        if(Board[i][0] == 'X' && Board[i][1] == 'X' && Board[i][2] == 'X') {
            return true;
        }
    }
    
    //Check column
    for(i = 0; i < 3; i++) {
        if(Board[0][i] == 'X' && Board[1][i] == 'X' && Board[2][i] == 'X') {
            return true;
        }
    }
    
    //Check diagnol
    if(Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X') {
        return true;
    }
    if(Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X') {
        return true;
    }
    
    return false;
}


bool checkFullBoard() {
    int i, j;
    //Checks if there's an empty space on board
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(!(Board[i][j] == 'O' || Board[i][j] == 'X')) {
                return false;
            }
        }
    }
    return true;
}