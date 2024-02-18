#include <iostream>
#include <vector>

const int SIZE = 9;

void displayGrid(const std::vector<std::vector<int>>& grid) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < SIZE; ++x) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool findEmptyCell(const std::vector<std::vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solveSudoku(std::vector<std::vector<int>>& grid) {
    int row, col;

    if (!findEmptyCell(grid, row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> sudokuGrid(SIZE, std::vector<int>(SIZE, 0));

    std::cout << "Enter the Sudoku puzzle (0 for empty cells):\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cin >> sudokuGrid[i][j];
        }
    }

    std::cout << "\nSudoku Puzzle:\n";
    displayGrid(sudokuGrid);

    if (solveSudoku(sudokuGrid)) {
        std::cout << "\nSudoku Solution:\n";
        displayGrid(sudokuGrid);
    } else {
        std::cout << "\nNo solution exists.\n";
    }

    return 0;
}
