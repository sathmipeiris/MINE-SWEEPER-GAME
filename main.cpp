#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Cell {
public:
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int adjacentMines;

    Cell() : isMine(false), isRevealed(false), isFlagged(false), adjacentMines(0) {}
};

class MinesweeperBoard {
private:
    int rows;
    int cols;
    vector<vector<Cell>> board;

    void placeMines(int numMines) {
        int totalCells = rows * cols;
        while (numMines > 0) {
            int randRow = rand() % rows;
            int randCol = rand() % cols;
            if (!board[randRow][randCol].isMine) {
                board[randRow][randCol].isMine = true;
                numMines--;
            }
        }
    }

    void calculateAdjacentMines() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!board[i][j].isMine) {
                    for (int ni = -1; ni <= 1; ++ni) {
                        for (int nj = -1; nj <= 1; ++nj) {
                            int niCoord = i + ni;
                            int njCoord = j + nj;
                            if (niCoord >= 0 && niCoord < rows && njCoord >= 0 && njCoord < cols &&
                                board[niCoord][njCoord].isMine) {
                                board[i][j].adjacentMines++;
                            }
                        }
                    }
                }
            }
        }
    }
public:
    MinesweeperBoard(int numRows, int numCols, int numMines) : rows(numRows), cols(numCols) {
        board.resize(rows, vector<Cell>(cols, Cell()));
        placeMines(numMines);
        calculateAdjacentMines();
    }

    void displayBoard() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j].isRevealed) {
                    if (board[i][j].isMine) {
                        cout << ".";
                    } else {
                        cout << board[i][j].adjacentMines << " ";
                    }
                } else if (board[i][j].isFlagged) {
                    cout << "F ";
                } else {
                    cout << "C ";
                }
            }
            cout << endl;
        }
    }

    void revealCell(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols && !board[row][col].isRevealed &&
            !board[row][col].isFlagged) {
            board[row][col].isRevealed = true;
            if (board[row][col].adjacentMines == 0) {
                for (int ni = -1; ni <= 1; ++ni) {
                    for (int nj = -1; nj <= 1; ++nj) {
                        revealCell(row + ni, col + nj);
                    }
                }
            }
        }
    }

        void toggleFlag(int row, int col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            board[row][col].isFlagged = !board[row][col].isFlagged;
        }
    }
};

int main(){

    return 0;
}