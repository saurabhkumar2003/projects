#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int BOARD_SIZE = 3;

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << "| ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (board[row][col] != ' ') {
            cout << "Cell already occupied. Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
