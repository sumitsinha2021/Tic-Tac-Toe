#include <iostream>
#include <vector>


void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}


void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}


bool isGameOver(const std::vector<std::vector<char>>& board, char& winner) {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            winner = board[i][0];
            return true;
        }
    }

    
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            winner = board[0][j];
            return true;
        }
    }

    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        winner = board[0][0];
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        winner = board[0][2];
        return true;
    }

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    winner = ' '; 
    return true;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3));
    initializeBoard(board);

    char currentPlayer = 'X';
    char winner = ' ';
    int row, col;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (true) {
        printBoard(board);

        
        std::cout << "Player " << currentPlayer << ", enter row and column (0-2) separated by space: ";
        std::cin >> row >> col;

        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        
        if (isGameOver(board, winner)) {
            printBoard(board);

            if (winner != ' ') {
                std::cout << "Player " << winner << " wins! Congratulations!" << std::endl;
            } else {
                std::cout << "It's a draw! Good game." << std::endl;
            }

            break;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
