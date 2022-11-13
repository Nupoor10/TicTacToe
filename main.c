#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare Tic-Tac-Toe board array
char board[3][3];
char a = 'X';
char b = 'O';

//Struct Variable for Player Details
struct playerInfo {
    char playerName[50];
    char playerChoice[50];
};

struct playerInfo Player1, Player2;
struct playerInfo *Player1ptr, *Player2ptr;

//Function Prototypes
void printBoard();
void resetBoard();
void welcomePlayer();
int playerMove1();
int playerMove2();
char checkWinner();
void printWinner(char l, int endGame);

int main()
{
    Player1ptr = &Player1;
    Player2ptr = &Player2;
    char winner = ' ';
    char response = ' ';
    //Loop will be executed till user response is YES
    do {
        //Resetting the variable value to NULL
        winner = ' ';
        response = ' ';
        printf("\n\nWELCOME TO A GAME OF TIC TAC TOE\n\n");
        //Resetting the board
        resetBoard();
        //Displaying the board
        printBoard();
        printf("\n\n\n");
        //Function to take in Player details
        welcomePlayer();
        printBoard();
        //Setting the variable that counts user moves, max allowed is 9
        int endGame = 9;
        //Loop will run till we don't get a winner AND we don't run out of moves
        while(winner == ' ' && endGame != 0)
        {
             printf("\n%s PLAY YOUR MOVE\n", Player1ptr->playerName);
             //Function takes in Player 1 input
             playerMove1();
             printBoard();
             printf("\nWell Played !!!\n\n");
             //Decrement no. of moves left
             endGame --;
             //Check for the winner
             winner = checkWinner();
             //If we get a winner or run out of moves, we break out of the loop
             if(winner != ' ' || endGame == 0)
             {
                break;
             }

             printf("\n%s PLAY YOUR MOVE\n", Player2ptr->playerName);
             //Function takes in Player 2 input
             playerMove2();
             printBoard();
             printf("\nWell Played !!!\n\n");
             endGame --;
             winner = checkWinner();
             if(winner != ' ' || endGame == 0)
             {
                break;
             }
        }

        //We break out of the loop if we get a winner or run out of moves
        //Function to declare the winner or whether it is a draw
        printWinner(winner, endGame);
        //User decides if they wish to continue playing
        printf("\nDO YOU WANT TO PLAY AGAIN ? ENTER Y FOR YES N FOR NO\n");
        scanf(" %c", &response);

    }while(response == 'Y');
}

//Resets all array values to NULL
void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

//Display the board
void printBoard()
{
    printf("\n %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n___|___|___");
    printf("\n %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n___|___|___");
    printf("\n %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

//Take user input for player details
void welcomePlayer()
{
    printf("\nWELCOME PLAYER 1");
    printf("\nEnter your Player Name: \n");
    scanf("%s", Player1ptr->playerName);
    printf("\nWELCOME %s", Player1ptr->playerName);
    //Loop will run till user enters permitted characters - X or O
    while(1) {
        printf("\nAre you playing X or O? Enter your choice here: ");
        scanf("%s", Player1ptr->playerChoice);
        if(strchr(Player1ptr->playerChoice, a) || strchr(Player1ptr->playerChoice, b)){
            printf("\nYOU WILL BE PLAYING : %s", Player1ptr->playerChoice);
            break;
           }
        else{
            //Alerts if the character is invalid and re-takes the user input
            printf("\nSorry you entered an Invalid Character! Enter Again: ");
            continue;
        }
    }


    printf("\n\n\nWELCOME PLAYER 2");
    printf("\nEnter your Player Name\n");
    scanf("%s", Player2ptr->playerName);
    printf("\nWELCOME %s", Player2ptr->playerName);
    while(1) {
        printf("\nAre you playing X or O? Enter your choice here: ");
        scanf("%s", Player2ptr->playerChoice);
        if(strchr(Player2ptr->playerChoice, a) || strchr(Player2ptr->playerChoice, b)){
            printf("\nYOU WILL BE PLAYING : %s", Player2ptr->playerChoice);
            break;
           }
        else{
            printf("\nSorry you entered an Invalid Character! Enter Again: ");
            continue;
        }
    }


    printf("\nLET THE GAME BEGIN !!! \n\n\n");
}

//Taking input for where the Player 1 wants to make their move
int playerMove1()
{
    int i, j;
    //Loop will execute until the player makes a move and a character is entered into the array
    do {
        printf("\nWhich place do you want to enter your character?");
        printf("\nEnter the row: ");
        scanf("%d", &i);
        printf("\nEnter the column: ");
        scanf("%d", &j);
        if (board[i-1][j-1] != ' '){
            //Alerts if the position entered is already full
            printf("\nSorry, Thus position is already full");
            continue;
        }
        else {
            //Saves the pre-decided user choice - X or O in the position decided
            board[i-1][j-1] = Player1ptr->playerChoice[0];
            break;
        }
    }while(board[i][j] == ' ');

}

//Taking input for where the Player 2 wants to make their move
int playerMove2()
{
    int i, j;
    do {
        printf("\nWhich place do you want to enter your character?");
        printf("\nEnter the row: ");
        scanf("%d", &i);
        printf("\nEnter the column: ");
        scanf("%d", &j);
        if (board[i-1][j-1] != ' '){
            printf("\nSorry, Thus position is already full");
            continue;
        }
        else {
            board[i-1][j-1] = Player2ptr->playerChoice[0];
            break;
        }
    }while(board[i][j] == ' ');
}

//Function the check for all cases of winning
char checkWinner()
{
    char noWinner = ' ';
    //Horizontal Cases
    if( board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        return board[0][0];
    }
    else if( board[1][0] == board[1][1] && board[1][1] == board[1][2]){
        return board[1][0];
    }
    else if( board[2][0] == board[2][1] && board[2][1] == board[2][2]){
        return board[2][0];
    }
    //Vertical Cases
    else if( board[0][0] == board[1][0] && board[1][0] == board[2][0]){
        return board[0][0];
    }
    else if( board[0][1] == board[1][1] && board[1][1] == board[2][1]){
        return board[0][1];
    }
    else if( board[0][2] == board[1][2] && board[1][2] == board[2][2]){
        return board[0][2];
    }
    //Diagonal Cases
    else if( board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    else if( board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }
    //If any case is true, will return the character - X or O that won
    //Value gets stored in winner variable
    //If no case is true will return NULL value
    else {
        return noWinner;
    }
}

//Function to declare the winner
void printWinner(char l, int endGame)
{
    // checks which player the character store in winner variable belongs and declares winner
    if( l == Player1ptr->playerChoice[0])
    {
        printf("\nPLAYER %s HAS WON !!!", Player1ptr->playerName);
    }
    else if ( l == Player2ptr->playerChoice[0])
    {
        printf("\nPLAYER %s HAS WON !!!", Player2ptr->playerName);
    }
    //If no character is returned and the player is out of moves, declares a draw
    else if ( l == ' ' && endGame == 0){
        printf("\nIT IS A TIE !!!");
    }
}
