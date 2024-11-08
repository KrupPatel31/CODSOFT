#include <bits/stdc++.h>
using namespace std;

char board[3][3];
char current_marker;
int current_player;

void initializeBoard()
{
    int slot = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '0' + slot;
            slot++;
        }
    }
}

void drawBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
}

bool placeMarker(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int checkWin()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

void swapPlayerAndMarker()
{
    if (current_marker == 'X')
        current_marker = 'O';
    else
        current_marker = 'X';

    current_player = (current_player == 1) ? 2 : 1;
}

void playGame()
{
    initializeBoard();
    current_marker = 'X';
    current_player = 1;
    int winner = 0;
    int slot;

    for (int i = 0; i < 9; i++)
    {
        drawBoard();
        cout << "Player " << current_player << " (" << current_marker << "), enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            i--; // Repeat this turn
            continue;
        }

        if (!placeMarker(slot))
        {
            cout << "Slot already taken! Try another slot.\n";
            i--; // Repeat this turn
            continue;
        }

        winner = checkWin();
        if (winner != 0)
        {
            drawBoard();
            cout << "Player " << winner << " wins!\n";
            return;
        }

        swapPlayerAndMarker();
    }

    drawBoard();
    cout << "It's a draw!\n";
}

int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}