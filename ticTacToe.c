#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//declare functions
void clearBoard();
void printBoard();
int checkTie();
void playerMove1();
void playerMove2();
void computerMove();
char checkWinner();


//declare variables
char board[9];
char player1 = 'X';
char player2 = 'O';
char computer = 'O';

int main()
{
    char winner = ' ';

    printf("Welcome to Tic Tac Toe!\n");

   // if pvp{
       printf("Player 1 is X and Player 2 is O.\n");

       // print board with spaces labeled 1-9 so the user knows which space is what

        clearBoard();

        while (winner == ' ' && checkTie() != 0)
        {
            printBoard();
            printf("Player 1's Turn (X)\n");
            playerMove1();
            winner = checkWinner();
            if (winner != ' ' || checkTie() == 0)
            {
                break;
            }
            printBoard();
            printf("Player 2's Turn (O)\n");
            playerMove2();
            winner = checkWinner();
            if (winner != ' ' || checkTie() == 0)
            {
                break;
            }
        }

        printBoard();

        if (winner == player1)
        {
            printf("Player 1 Wins!");
        }
        else if (winner == player2)
        {
            printf("Player 2 Wins!");
        }
        else
        {
            printf("It is a Tie!");
        }

       // check if move is valid
       //     if not valid keep asking until valid

       // ask player 2 for move

      //  check valid

      //  check for win
      //      if no win, loop
      //      if win then ask if want to play again
      //          if yes then start over
   // }
   // if comp{
   //     say that player 1 is x, comp is o

   //     print board with spaces labeled 1-9 so the user knows which space is what

   //     clear board

    //    print game board

    //    ask player 1 for move (1-9)

    //    check if move is valid
     //       if not valid keep asking until valid
//
     //   randomize comp move

    //    check valid
     //       if not, keep randomizing until valid

    //    check for win
     //       if no win, loop
     //       if win then ask if want to play again
      //          if yes then start over
   // }
   return 0;
}

void clearBoard()
{
    for (int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0], board[1], board[2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[3], board[4], board[5]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[6], board[7], board[8]);
    printf("\n");
}

int checkTie()
{
    int spacesFree = 9;

    for (int i = 0; i < 9; i++)
    {
        if (board[i] != ' ')
        {
            spacesFree--;
        }
    }
    return spacesFree;
}

void playerMove1()
{
    int place1;

    do
    {
        printf("Enter your move(1-9): ");
        scanf("%d", &place1);
        place1--;

        if (board[place1] != ' ')
        {
            printf("Invalid Input\n");
        }
        else
        {
            board[place1] = player1;
            break;
        }
    } while (board[place1] != ' ');
    
}

void playerMove2()
{
    int place2;

    do
    {
        printf("Enter your move(1-9): ");
        scanf("%d", &place2);
        place2--;

        if (board[place2] != ' ')
        {
            printf("Invalid Input\n");
        }
        else
        {
            board[place2] = player2;
            break;
        }
    } while (board[place2] != ' ');
    
}

char checkWinner()
{
    //rows
    if (board[0] == board[1] && board[0] == board[2])
    {
        return board[0];
    }
    if (board[3] == board[4] && board[3] == board[5])
    {
        return board[3];
    }
    if (board[6] == board[7] && board[6] == board[8])
    {
        return board[6];
    }

    //columns
    if (board[0] == board[3] && board[0] == board[6])
    {
        return board[0];
    }
    if (board[1] == board[4] && board[1] == board[7])
    {
        return board[1];
    }
    if (board[2] == board[5] && board[2] == board[8])
    {
        return board[2];
    }

    //diagonals
    if (board[0] == board[4] && board[0] == board[8])
    {
        return board[0];
    }
    if (board[2] == board[4] && board[2] == board[6])
    {
        return board[2];
    }

    return ' ';
}

void computerMove()
{
    srand(time(0));
    int place3;

    do
    {
        place3 = rand() % 9;
    } while (board[place3] != ' ');
        
    board[place3] = computer;
}
