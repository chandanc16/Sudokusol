#include <iostream>
using namespace std;

#define N 9

// Function to print the Sudoku board
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Check if it's safe to place num in the given row and column
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check row and column
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            // Look for an empty cell
            if (grid[row][col] == 0) {
                // Try all possible values
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;

                        if (solveSudoku(grid))
                            return true;

                        // Backtrack
                        grid[row][col] = 0;
                    }
                }
                return false; // Trigger backtracking
            }
        }
    }
    return true; // Solved
}

// Simple input function
void inputGrid(int grid[N][N]) {
    cout << "Enter the Sudoku puzzle (0 for empty cells):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
}

int main() {
    int grid[N][N];

    inputGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists for the given Sudoku.\n";
    }

    return 0;
}
