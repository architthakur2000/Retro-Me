#include <stdio.h> //importing input-output files, which helps us use functions like printf, scanf, fopen, fclose etc. 
#include <stdlib.h> //importing lib that allows memory allocation, random number generation, string conversions, and program termination. 
#include <ctype.h> //omporting lib that specifies the type of character in the code.
#include <time.h> // import lib that gives you  acees to the currec=t time and date.


char board[3][3];
const char PLAYER = 'X';
const char COMP = 'O';

/**
 * The follwing 7 function prototypes. 
 */
void resetBoard(){ // we reset it when the game is completed. We need to set all the indexes as an empty string. 
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            board[i][j] = ' ';
        }
    }

} // board is 2D array, which could be reset. 


void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]); // we have %c as he placeholder which determines the skeletonn output. It takes the values in the board[i][j]
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");


} // will print the 2D array which is our board.


int checkFreeSpaces(){
    int freeSpaces = 9;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != ' '){ // if the spot we are on is currently occupied then we decrement the amount of free spaces. 
                freeSpaces--;
            }
        }
    }
    return freeSpaces;

} // will check for free spaces in a 2D array. 


void playerMove(){ //it takes the position of the player. 
    int x;
    int y; 
    
    do{
        printf("Enter row #(1-3): ");
        scanf("%d", &x); //Scans decimal value from the input and then stores it in an address. & operator gets the address of the variable. 
        x--; // because user doesn't know the array starts from 0. 
        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move!\n");
        }else{
            board[x][y] = PLAYER;
            break; //we put break here because we wanna check if the spot still has some value. If it is already filled, then we need to ask them to entera  different coordinate.
        }

    } while (board[x][y] != ' ');
} // will account the player's input and decide where they'd like to move to. 


void computerMove(){
    // create a seed based on random number.
    srand(time(0)); //srand sets the seed value of a random number generator. 
    int x;
    int y;
    if(checkFreeSpaces() > 0){
        do 
        {
            x = rand() % 3;
            y = rand() % 3;
        }while (board[x][y] != ' ');
        
        board[x][y] = COMP;

    }
    else{
        printf(" ");
    }

} // wil account the computer's input


char checkWinner(){
    //check our rows
    for(int i=0; i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    // check our columns
    for(int i=0; i<3;i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    //check diagonal 1
    if(board[0][0]==board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    //check diagonal 2
    if(board[0][2]==board[1][1] && board[0][2] == board[2][0]){
        return board[0][2];
    }
    return ' ';
    
} // based on the rules, this will declare the winner (computer or the Person)


void printWinner(char winner){
    if(winner == PLAYER){
        printf("You win!");
    }
    else if(winner == COMP){
        printf("You Lose!");
    }
    else{
        printf("It's a tie");
    }

} // will print the winner. It will take in a character so the data type is Char


int main()
{
    char winner = ' ';

    resetBoard(); // reset the board after there is a winner. 
    while(winner == ' ' && checkFreeSpaces() != 0){ // we do this because we have to print the board after each chance. 
        printBoard(); // prints the board

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
        
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }
        



    }
    printBoard();
    printWinner(winner);

    return 0;
}
