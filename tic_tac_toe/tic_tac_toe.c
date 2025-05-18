/******************************************
 * Name: Tomer Cohen
 *Student ID: 209200658
 *Sumbit ID: cohentol
 ******************************************/

#include <stdio.h>
void playGame();

int main()
{
    // start the game.
    printf("Would you like to start? (y/n)\n");
    char answer;
    answer=getchar();
    // check the answer if it y\n.
    if (answer == 'y')
    {
        // call the game function
        playGame();

        // while loop to continue the game
        // after wrong input or game's end

        while (1)
        {
            // asking the user if he want to play again.
            printf("Would you like to continue? (y/n)\n");

           /* Get the answer from the user and check if its not 
           y for case we had more input but one of the
           players win earlier*/

            answer=getchar();
            //check if the answer is 'y' or 'n' and if not get another char
            if (answer != 'y' && answer != 'n')
            {
            while (answer != 'y' && answer != 'n')
            {
                answer= getchar();
            }
            }
            // play or not based on the user answer.
            if (answer == 'y')
                playGame();
            else
            {
                printf("YEET");
                break;
            }
        }
    }
    // end the game if the user didnt want to start the game
    else
        printf("YEET");
}
//end of main


/********************************
* function name: playGame*
* The Input: None
* The output: The funcion operate the game and
 she handle wrong input and prints the board if
 there is win situation *
* The Function operation: The function start asking
 the user for his  game sequence than put
X or O according to the user turn and she check
if there is winner every step while she realize
there is a winner she print the board
she also count the number of the turns and when
she get to 64 she realizes that the board
is full with no winner
and she prints the board *
***************************************************/

void playGame()
{
    // decalre the variables of the function.
    int firstPlayerWin = 1, secondPlayerWin = 2;
    int checkWin = 0;
    int first = 0, second = 0,third = 0;
    int firstTurn = 1, secondTurn = 2;
    int turn = firstTurn;
    int i = 0, j = 0, k = 0;
    int turnIndex = 0, fullBoardPlay=64;
    int numberOfBoards=4;
    int numberOfRows=4;
    int numberOfColumns=4;
    int placesInRow=4;
    // decalre the 3d array that is the board of the game.
    char gameBoard[numberOfBoards][numberOfRows][placesInRow];
    // fill the array with '*'.

    //first loop for the boarn number
    for (i = 0; i < numberOfBoards; i++)
    {
        //second for the row number
        for (j = 0; j < numberOfRows; j++)
        {
            //third for each place
            for (k = 0; k < placesInRow; k++)
            {
                gameBoard[i][j][k] = '*';
            }
        }
    }
    // ask the user for his game sequence
    printf("Please enter your game sequence.\n");

    /*while loop to handle the game- the loop get the
     user sequence and handle one digit each time
    while the first is the board the second is row
    and the third is column(example the digits 0 0 0 will
    be the first board, first row and first column)
    after every play is check the board for a winner
    if we have one it print the board.*/

    while (1)
    {
        // scan the input to realize the user play
        scanf(" %d", &first);
        scanf(" %d", &second);
        scanf(" %d", &third);
        //get +1 to the turn index to handle tie case
        turnIndex++;
        // check the first digit if it is in the legal range(0-3)
        if (first != 0 && first != 1 && first != 2 && first != 3)
        {
           //if its wrong print it to the user and return to the main
            printf("Input incorrect.\n");
            return;
        }
        // check the second digit if it is in the legal range(0-3)
        if (second != 0 && second != 1 && second != 2 && second != 3)
        {
          //if its wrong print it to the user and return to the main
            printf("Input incorrect.\n");
            return;
        }
        // check the third digit if it is in the legal range(0-3)
        if (third != 0 && third != 1 && third != 2 && third != 3)
        {
            // if its wrong print it to the user and return to the main
            printf("Input incorrect.\n");
            return;
        }
        // check if the user play alredy played before on the board
        if (gameBoard[first][second][third] == 'O' ||
            gameBoard[first][second][third] == 'X')
        {
            // if its alredy played return to the main
            printf("Input incorrect.\n");
            return;
        }

        /* if the play is legal- put the first player sign-
        'X' on the board */

        if (turn == firstTurn)
        {
            //put the 'X' sign in the array
            gameBoard[first][second][third] = 'X';
            turn = secondTurn;

            // check each board rows
            for (i = 0; i < numberOfBoards; i++)
            {
                for (k = 0; k < numberOfRows; k++)
                {

                    /*check the place according to the loop
                    while the first is the board second is row
                    and the third is the first, second, third and forth
                    places in the row */
                    
                    if (gameBoard[i][k][0]=='X' &&gameBoard[i][k][1]=='X'
                    &&gameBoard[i][k][2]=='X' &&gameBoard[i][k][3]=='X')
                    {
                        checkWin = firstPlayerWin;
                    }
                }
            }
            // check each board columns(4 for every board)
            for (i = 0; i < numberOfBoards; i++)
            {
                for (k = 0; k < numberOfColumns; k++)
                {
                    
                    /*check the place according to the loop
                    while the first is the board second is row
                    and the third is the first, second,
                    third and forth places in the column */

                    if (gameBoard[i][0][k]=='X' &&gameBoard[i][1][k]=='X'
                    &&gameBoard[i][2][k]=='X' &&gameBoard[i][3][k]=='X')
                    {
                        checkWin = firstPlayerWin;
                    }
                }
            }
            // check the 2d diagonal line(2 for each board)
            for (i = 0; i < numberOfBoards; i++)
            {

                /* check each board diagonal while the second 
                and third number in the array is the same*/

                if (gameBoard[i][0][0]=='X' &&gameBoard[i][1][1]=='X'
                &&gameBoard[i][2][2]=='X' &&gameBoard[i][3][3]=='X')
                {
                    checkWin = firstPlayerWin;
                }

                /* check each board diagonal while the second 
                and third number in the array are diffrent*/

                if (gameBoard[i][0][3]=='X' &&gameBoard[i][1][2]=='X'
                &&gameBoard[i][2][1]=='X' &&gameBoard[i][3][0]=='X')
                {
                    checkWin = firstPlayerWin;
                }
            }
 
            // check 3d columns(16 options)
            for (i = 0; i < numberOfRows; i++)
            {
                for (k = 0; k < placesInRow; k++)
                {

                    /* check the column while the row number and
                    place in row for each board is the same
                    and check for 4 boards*/

                    if (gameBoard[0][i][k]=='X' &&gameBoard[1][i][k]=='X'
                    &&gameBoard[2][i][k]=='X'&&gameBoard[3][i][k]=='X')
                    {
                        checkWin = firstPlayerWin;
                    }
                }
            }

            /*check the 4 3d diagonal line(from corner to corner)-
             checking pecific numbers according to 
             the diagonal lines*/ 

            if (gameBoard[0][0][0]=='X'&&gameBoard[1][1][1]=='X'
            &&gameBoard[2][2][2]=='X'&&gameBoard[3][3][3]=='X')
            {
                checkWin = firstPlayerWin;
            }
            if (gameBoard[0][0][3]=='X'&&gameBoard[1][1][2]=='X'
            &&gameBoard[2][2][1] == 'X' && gameBoard[3][3][0] == 'X')
            {
                checkWin = firstPlayerWin;
            }
            if (gameBoard[3][0][0]=='X' &&gameBoard[2][1][1]=='X'
            &&gameBoard[1][2][2] == 'X'&&gameBoard[0][3][3] == 'X')
            {
                checkWin = firstPlayerWin;
            }
            if (gameBoard[3][0][3]=='X' &&gameBoard[2][1][2] =='X'
            && gameBoard[1][2][1]=='X' &&gameBoard[0][3][0]=='X')
            {
                checkWin = firstPlayerWin;
            }
            //check if we have winner and print the board
            if (checkWin == firstPlayerWin)
            {
                //prints the win message
                printf("X is the winner.\n");

                //for loop to print the board with numbers
                //first for each board

                for (i = 0; i < numberOfBoards; i++)
                {
                    //second for each row
                    for (j = 0; j < numberOfRows; j++)
                    {

                        //third for each number or sign in the array
                        //for loop to print the number places

                        for (k = 0; k < placesInRow; k++)
                        {
                            printf("(%d %d %d) ", i, j, k);
                        }
                        //print the board game signs
                        for (k = 0; k < placesInRow; k++)
                        {
                            printf("%c ", gameBoard[i][j][k]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                return;
            }
            //end of the if of the win option
        }
        //end of the first option of the 'if'.

        /* if its not the first player turn-
        put the first player sign-'O' on the board*/

        else
        {

            /* put the 'O' on the board and
            make the turn variable 'firstTurn' */

            gameBoard[first][second][third] = 'O';
            turn = firstTurn;

            // check each board rows
            for (i = 0; i < numberOfBoards; i++)
            {
                for (k = 0; k < numberOfRows; k++)
                {

                    /*check the place according to the loop
                    while the first is the board second is row
                    and the thirs is the first, second, third and forth
                    plces in the row */

                    if (gameBoard[i][k][0]=='O' &&gameBoard[i][k][1]=='O'
                    &&gameBoard[i][k][2]=='O' &&gameBoard[i][k][3]=='O')
                    {
                        checkWin = secondPlayerWin;
                        break;
                    }
                }
            }
            // check each board colums
            for (i = 0; i < numberOfBoards ; i++)
            {
                for (k = 0; k <numberOfColumns; k++)
                {

                    /*check the place according to the loop
                    while the first is the board second is row
                    and the third is the first, second, third and forth
                    plces in the column */

                    if (gameBoard[i][0][k]=='O' &&gameBoard[i][1][k]=='O'
                    &&gameBoard[i][2][k]=='O' &&gameBoard[i][3][k]=='O')
                    {
                        checkWin = secondPlayerWin;
                    }
                }
            }
            // check the 2d diagonal line(2 for each board)
            for (i = 0; i < numberOfBoards; i++)
            {

                /* check each board diagonal while the second 
                and third number in the array is the same*/

                if (gameBoard[i][0][0]=='O' &&gameBoard[i][1][1]=='O'
                &&gameBoard[i][2][2]=='O' &&gameBoard[i][3][3]=='O')
                {
                    checkWin = secondPlayerWin;
                }

                /* check each board diagonal while the second 
                and third number in the array are diffrent*/

                if (gameBoard[i][0][3]=='O' &&gameBoard[i][1][2]=='O'
                &&gameBoard[i][2][1]=='O' &&gameBoard[i][3][0]=='O')
                {
                    checkWin = secondPlayerWin;
                }
            }

            // check 3d columns(16 options)
            for (i = 0; i < numberOfRows; i++)
            {
                for (k = 0; k < placesInRow; k++)
                {

                    /* check the column while the row and
                    and place is the same and the first number of the
                    boards checked*/

                    if (gameBoard[0][i][k]=='O' &&gameBoard[1][i][k]=='O'
                    &&gameBoard[2][i][k]=='O' &&gameBoard[3][i][k]=='O')
                    {
                        checkWin = secondPlayerWin;
                    }
                }
            }

            /*check the 4 3d diagonal line(from corner to corner)-
             checking pecific numbers according to 
             the diagonal lines*/ 

            if (gameBoard[0][0][0]=='O' &&gameBoard[1][1][1]=='O'
            &&gameBoard[2][2][2]=='O' &&gameBoard[3][3][3]=='O')
            {
                checkWin = secondPlayerWin;
            }
            if (gameBoard[0][0][3]=='O' &&gameBoard[1][1][2]=='O'
            &&gameBoard[2][2][1]=='O' &&gameBoard[3][3][0]=='O')
            {
                checkWin = secondPlayerWin;
            }
            if (gameBoard[3][0][0]=='O' &&gameBoard[2][1][1]=='O'
            &&gameBoard[1][2][2]=='O' &&gameBoard[0][3][3]=='O')
            {
                checkWin = secondPlayerWin;
            }
            if (gameBoard[3][0][3]=='O' &&gameBoard[2][1][2]=='O'
            &&gameBoard[1][2][1]=='O' &&gameBoard[0][3][0]=='O')
            {
                checkWin = secondPlayerWin;
            }


            //check if we have winner and print the board
            if (checkWin == secondPlayerWin)
            {
                //print the win message
                printf("O is the winner.\n");
                //for loop to print the board with numbers
                for (i = 0; i < numberOfBoards; i++)
                {
                    for (j = 0; j < numberOfRows; j++)
                    {
                        //for loop to print the number places
                        for (k = 0; k <placesInRow ; k++)
                        {
                            printf("(%d %d %d) ", i, j, k);
                        }
                        //print the board game signs
                        for (k = 0; k < placesInRow; k++)
                        {
                            printf("%c ", gameBoard[i][j][k]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                return;
            }
            //end of if of the win




            /* case of Tie- all the places
             on the board are full(64 plays) */

            if (turnIndex==fullBoardPlay)
            {
                //print the Tie message
                printf("Tie.\n");
                //for loop to print the board with numbers
                for (i = 0; i < numberOfBoards ; i++)
                {
                    for (j = 0; j <numberOfRows ; j++)
                    {
                        //for loop to print the number places
                        for (k = 0; k < placesInRow; k++)
                        {
                            printf("(%d %d %d) ", i, j, k);
                        }
                        //print the board game signs
                        for (k = 0; k < placesInRow; k++)
                        {
                            printf("%c ", gameBoard[i][j][k]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                return;
            }
            //end of tie 'if'
        }
        //end of else option
    }
    //end of while loop
}

//end of function
