#include <iostream>
using namespace std;
const int N_MAX = 10;

bool isSafe(int board[N_MAX][N_MAX], int row, int col, int N) {
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    for (int i = row, j = col; j >= 0 && i < N; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueensUtil(int board[N_MAX][N_MAX], int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, N))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void solveNQueens(int N) {
    int board[N_MAX][N_MAX] = {0};

    if (!solveNQueensUtil(board, 0, N))
        cout << "Solution does not exist";
    else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}







































/*
#include <iostream>

using namespace std;

const int N_MAX = 10;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N_MAX][N_MAX], int row, int col, int N) {
    // Check the row on the left side
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[N_MAX][N_MAX], int col, int N) {
    // If all queens are placed then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; ++i) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col, N)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1, N))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution, then backtrack
            board[i][col] = 0; // Backtrack
        }
    }

    // If the queen can not be placed in any row in this column, return false
    return false;
}

// Function to solve the N-Queens problem
void solveNQueens(int N) {
    int board[N_MAX][N_MAX] = {0}; // Initialize an empty chessboard

    if (!solveNQueensUtil(board, 0, N))
        cout << "Solution does not exist";
    else {
        // Print the solution
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}










*/









