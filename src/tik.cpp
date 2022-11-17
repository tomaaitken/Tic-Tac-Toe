/**
 * A sample Tic Toc Toe game
 * ----------------
 * @attention
 * This app was written only to show how to upload a simple project in github.
 * This code is not a good way to implement a tic toc toe game.
 */
#include <iostream>
using namespace std;

const int board_size = 3;
char board[board_size][board_size]; /*tic-toc-toe board game*/
int x, y, stop = 0, index1 = 0;


void printGame();
void askUserToPlay();
void printMenu();
void saveMove(int x, int y);
bool checkGameState();
void computersMove();
void printGameOver();
void clear();

int main()
{
    clear();
    // set initial computer position
    board[1][1] = 'o';

    do
    {
        printMenu();
        printGame();
        askUserToPlay();
        saveMove(x, y);
        computersMove();
        printGame();
    } while (checkGameState());

    return 0;
}

void printGame()
{
    cout << endl;
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
    }
}

void askUserToPlay()
{

    bool wrongMove = true;
    do
    {
        cout << endl
             << "Enter row and column (e.g. 0 1): ";
             
        cin >> x >> y;
        if (board[x][y] == 'x' || board[x][y] == 'o' || x > 2 || x < 0 || y > 2 || y < 0)
        {
            cout << endl
                 << "Wrong Move!!! Try again." << endl;
        }
        else
        {
            wrongMove = false;
        }
    } while (wrongMove);
}

void printMenu()
{
    cout << endl;
    cout << "*************************************" << endl;
    cout << "*******    Tic Tac Toe Game     *****" << endl;
    cout << "*******     Let's Have Fun      *****" << endl;
    cout << "*************************************" << endl << endl;
}

void saveMove(int x, int y)
{
    board[x][y] = 'x';
}

bool checkGameState()
{

    int numberX = 0;

    // Cheking rows
    for (int i = 0; i < board_size; i++)
    {
        if (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x' || board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o')
        {
            printGameOver();
            return false;
        }
    }
    // cheking columns
    for (int i = 0; i < board_size; i++)
    {
        if (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x' || board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == 'o')
        {
            printGameOver();
            return false;
        }
    }
    // elenxo tes diagonios
    if ((board[1][1] == 'o' && board[0][0] == 'o' && board[2][2] == 'o') || (board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == 'o'))
    {
        printGameOver();
        return false;
    }
    // elenxo gis isopalia
    if (stop == 4)
    {
        printGameOver();
        return false;
    }

    return true;
}

void printGameOver()
{
    cout << endl;
    cout << "*************************************" << endl;
    cout << "*************  GAME OVER ************" << endl;
    cout << "********** !!! TRY AGAIN !!!  ******" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}

void computersMove()
{

    index1 = 0;
    stop++;

    for (index1 = 0; index1 < board_size; index1++)
    {
        for (int i = 0; i < board_size; i++)
        {
            for (int j = i + 1; j < board_size; j++)
            {

                if (board[index1][i] == board[index1][j])
                {

                    if (board[index1][j] == 'o' && board[index1][board_size - j - i] == ' ')
                    {
                        board[index1][board_size - j - i] = 'o';

                        return;
                    }

                    else if (board[index1][j] == 'x' && board[index1][board_size - j - i] == ' ')
                    {
                        board[index1][board_size - j - i] = 'o';

                        return;
                    }
                }

                if (board[i][index1] == board[j][index1])
                {

                    if (board[j][index1] == 'o' && board[board_size - j - i][index1] == ' ')
                    {
                        board[board_size - j - i][index1] = 'o';

                        return;
                    }

                    else if (board[j][index1] == 'x' && board[board_size - j - i][index1] == ' ')
                    {
                        board[board_size - j - i][index1] = 'o';

                        return;
                    }
                }
            }
        }
    }

    if (index1 == 3)
    {
        for (int i = 0; i < board_size; i++)
        {
            for (int j = 0; j < board_size; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'o';
                    return;
                }
            }
        }
    }
}
void clear()
{
    // make space in all borad
    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            board[i][j] = ' ';
        }
    }

}