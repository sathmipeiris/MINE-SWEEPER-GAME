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
    bool isGameWon() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!board[i][j].isRevealed && !board[i][j].isMine) {
                    return false;
                }
            }
        }
        return true;
    }

     bool isGameLost() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j].isRevealed && board[i][j].isMine) {
                    return true;
                }
            }
        }
        return false;
    }
};



int convertLetterToIndex(char letter, int max) {
    switch (letter) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'G':
        return 6;
    case 'H':
        return 7;
    case 'I':
        return 8;
    case 'J':
        return 9;
    case 'K':
        return 10;
    case 'L':
        return 11;
    case 'M':
        return 12;
    case 'N':
        return 13;
    case 'O':
        return 14;
    case 'P':
        return 15;
    case 'Q':
        return 16;
    case 'R':
        return 17;
    case 'S':
        return 18;
    case 'T':
        return 19;
    default:
        return -1;  // Invalid input
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int rows, cols, numMines;
    int fieldOption;
    cout << "----------------MINE SWEEPER GAME-----------" << endl;
    cout << "Levels: " << endl;
    cout << "\t1. Easy " << endl;   // 10*10 grid and 12 mines
    cout << "\t2. Medium" << endl;  // 15*15 grid and 18 mines
    cout << "\t3. Hard" << endl;    // 20*20 grid and 24 mines
    cout << "Enter Level Option: ";
    cin >> fieldOption;

    if (fieldOption == 1) {
        rows = 10;
        cols = 10;
        numMines = 12;
    } else if (fieldOption == 2) {
        rows = 15;
        cols = 15;
        numMines = 18;
    } else if (fieldOption == 3) {
        rows = 20;
        cols = 20;
        numMines = 24;
    } else {
        cout << "Error: Invalid Level Option." << endl;
        return 1;
    }

    MinesweeperBoard gameBoard(rows, cols, numMines);

    while (true) {
        gameBoard.displayBoard();

        string command;
        cout << "Enter command (e.g., {A B R} to reveal, {A B F} to flag:): ";
        char row, col;
        cin >> row >> col;
        int iRow = convertLetterToIndex(row, rows);
        int iCol = convertLetterToIndex(col, cols);
        cin >> command;

        if (command == "F") {
            gameBoard.toggleFlag(iRow, iCol);
        } else if (command == "R") {
            if (gameBoard.isGameLost()) {
                cout << "Game Over! You hit a mine." << endl;
                break;
            }
            gameBoard.revealCell(iRow, iCol);
            if (gameBoard.isGameWon()) {
                cout << "Congratulations! You cleared the board without hitting any mines." << endl;
                break;
            }
        }
    }

    return 0;
}