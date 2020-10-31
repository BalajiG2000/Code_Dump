#include <stdio.h>
#include <stdlib.h>
#define AI 1
#define PLAYER 2
#include <limits.h>
void initialise(char board[3][3])
{
    char k = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = k++;
        }
    }
}

void display(char board[3][3])
{
    printf("\n\n");

    printf("\t\t\t  %c | %c  | %c  \n", board[0][0], board[0][1], board[0][2]);

    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0], board[1][1], board[1][2]);

    printf("\t\t\t--------------\n");
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], board[2][1], board[2][2]);

    return;
}

int columnCrossed(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])

            return (1);
    }
    return 0;
}

int rowCrossed(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])

            return (1);
    }
    return (0);
}

int diagonalCrossed(char board[3][3])
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])

        return 1;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])

        return 1;

    return (0);
}

int gameOver(char board[3][3])
{
    if (rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board))
    return 1;
    else
    {
        return 0;
    }
    
}

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}
int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int eval(char b[3][3])
{
    if (gameOver(b) == 1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
            {
                if (b[i][0] == 'x')
                    return 1;
                else if (b[i][0] == 'o')
                    return -1;
            }
        }

        for (int j = 0; j < 3; j++)
        {
            if (b[0][j] == b[1][j] && b[1][j] == b[2][j])
            {
                if (b[0][j] == 'x')
                    return 1;
                else if (b[0][j] == 'o')
                    return -1;
            }
        }

        if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        {
            if (b[0][0] == 'x')
                return 1;
            else if (b[0][0] == 'o')
                return -1;
        }
        if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
        {
            if (b[0][2] == 'x')
                return 1;
            else if (b[0][2] == 'o')
                return -1;
        }
    }

    return 0;
}

int AreMovesLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4' || board[i][j] == '5' || board[i][j] == '6' ||
                board[i][j] == '7' || board[i][j] == '8' || board[i][j] == '9')
                return 1;
        }
    }
    return 0;
}

int minimax(char board[3][3], int depth, int isComp)
{
    char hold;
    char tag;
    int score = eval(board);
    if (score == 1 || score ==-1)
        return score;
    
    if (AreMovesLeft(board) == 0)
        return 0;
    if (isComp)
    {
        int best = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4' || board[i][j] == '5' || board[i][j] == '6' ||
                //    board[i][j] == '7' || board[i][j] == '8' || board[i][j] == '9')
                if (board[i][j] == 'x' || board[i][j] == 'o')
                    continue;
                else
                {
                    hold = board[i][j];
                    board[i][j] = 'x';
                    int move = minimax(board, depth + 1, !isComp);
                    board[i][j] = hold;

                    if (move > best)
                    {
                        best = move;
                        tag = hold;
                    }
                }
            }
        }
        return best;
    }

    else
    {

        int best = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                // if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4' || board[i][j] == '5' || board[i][j] == '6' ||
                //    board[i][j] == '7' || board[i][j] == '8' || board[i][j] == '9')
                if (board[i][j] == 'x' || board[i][j] == 'o')
                    continue;
                else
                {
                    hold = board[i][j];
                    board[i][j] = 'o';
                    int move = minimax(board, depth + 1, isComp);
                    board[i][j] = hold;

                    if (move < best)
                    {
                        best = move;
                        tag = hold;
                    }
                }
            }
        }
        return best;
    }
}

char bestMove(char board[3][3])
{
    int bestVal = INT_MIN;
    char hold;
    char tag;
    for (int i = 0; i < 3; i++)
    {
    line:
        for (int j = 0; j < 3; j++)
        {

            // if (board[i][j] == '1' || board[i][j] == '2' || board[i][j] == '3' || board[i][j] == '4' || board[i][j] == '5' || board[i][j] == '6' ||
            //    board[i][j] == '7' || board[i][j] == '8' || board[i][j] == '9')
            if (board[i][j] == 'x' || board[i][j] == 'o')//if move is available
                continue;
            else
            {
                hold = board[i][j];
                board[i][j] = 'x'; 
                int move = minimax(board, 0, 0);
                // printf("Move is %d and Best val is %d\n", move,bestVal);
                // printf("Hold is %c\n", hold);
                board[i][j] = hold;
                if (move > bestVal)
                {
                    bestVal = move;
                    tag = hold;
                }
            }
        }
    }
    // printf("best pos is %c\n", tag);
    // printf("best val is %d\n", bestVal);
    return tag;
}

void game(char board[3][3], int start)
{
    int player = start;
    char done[9]; //a character array for storing all the positions which have been filled
    int count = 0;
    while (gameOver(board) == 0 && count < 9)
    {
        if (player == PLAYER)
        {
            char pos;
            fflush(stdin);
            printf("\tYour turn....Enter a position\n");
            scanf("%c", &pos);
            done[count++] = pos;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == pos)
                        board[i][j] = 'x';
            }
            display(board);
            player = AI;
        }
        else if (player == AI)
        { /*int num;
            label :  num = (rand() %  (9 - 1 + 1)) + 1;
            char c='0'+num;
             
            for(int k=0;k<count;k++)
            {
                if(done[k]==c)
                goto label;
            }
            done[count++]=c;*/

            char c = bestMove(board);
            done[count++] = c;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == c)
                        board[i][j] = 'o';
                }
            }
            printf("\tComupter's Turn\n");
            display(board);
            player = PLAYER;
        }
    }

    if (gameOver(board) == 0 &&
        count == 9)
        printf("\t\tIt's a DRAW!\n");

    else
    {
        if (player == PLAYER)
            printf("\t\tYOU LOSE!\n");
        if (player == AI)
            printf("\t\tYOU WON!\n");
    }
}

int main()
{
    char board[3][3];
    initialise(board);
    printf("\tLet the game begin...\n");
    display(board);
    game(board, AI);
    return 0;
}
