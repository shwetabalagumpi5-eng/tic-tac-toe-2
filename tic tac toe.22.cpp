#include <iostream>
using namespace std;

// Display the current game board
void displayBoard(char board[3][3])
{
    cout << "\n";
    cout << "     1   2   3\n";
    cout << "   -------------\n";

    for (int i = 0; i < 3; i++)
    {
        cout << " " << i + 1 << " | ";

        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
                cout << " | ";
        }

        cout << " |\n";
        cout << "   -------------\n";
    }
}

// Check whether the current player has won
bool checkWin(char board[3][3], char player)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player)
        {
            return true;
        }
    }

    // Check main diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    // Check opposite diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Check whether the board is full
bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }

    return true;
}

int main()
{
    // Initialize 3x3 character matrix
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int row, column;

    cout << "=============================\n";
    cout << "       TIC-TAC-TOE GAME      \n";
    cout << "=============================\n";
    cout << "Player 1: X\n";
    cout << "Player 2: O\n";

    while (true)
    {
        displayBoard(board);

        cout << "\nPlayer " << currentPlayer << "'s turn.\n";
        cout << "Enter row and column (1-3): ";
        cin >> row >> column;

        // Validate input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Please enter numbers only.\n";
            continue;
        }

        // Convert to array indexes
        row--;
        column--;

        // Check whether position is valid
        if (row < 0 || row >= 3 || column < 0 || column >= 3)
        {
            cout << "Invalid position! Row and column must be between 1 and 3.\n";
            continue;
        }

        // Check whether position is already occupied
        if (board[row][column] != ' ')
        {
            cout << "That position is already occupied! Try again.\n";
            continue;
        }

        // Place player's mark
        board[row][column] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "\nPlayer " << currentPlayer << " wins!\n";
            break;
        }

        // Check for draw
        if (checkDraw(board))
        {
            displayBoard(board);
            cout << "\nThe game is a draw!\n";
            break;
        }

        // Switch player
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }

    cout << "\nThank you for playing Tic-Tac-Toe!\n";

    return 0;
}

