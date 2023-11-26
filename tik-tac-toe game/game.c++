#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void printBoard() const {
        std::cout << " 1 | 2 | 3 \n";
        std::cout << "-----------\n";
        std::cout << " 4 | 5 | 6 \n";
        std::cout << "-----------\n";
        std::cout << " 7 | 8 | 9 \n\n";

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << " " << board[i][j] << " ";
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "-----------\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (position < 1 || position > 9 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        switchPlayer();
        return true;
    }

    char checkWinner() const {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
                return board[i][0];
        }

        // Check columns
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
                return board[0][i];
        }

        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
            return board[0][0];

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
            return board[0][2];

        return ' ';
    }

    bool isBoardFull() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

public:
    char getCurrentPlayer() const {
        return currentPlayer;
    }
};

int main() {
    TicTacToe game;
    int position;

    std::cout << "Welcome to Tic-Tac-Toe!\n";
    game.printBoard();

    do {
        std::cout << "Player " << game.getCurrentPlayer() << ", enter your move (1-9): ";
        std::cin >> position;

        if (game.makeMove(position)) {
            game.printBoard();
            char winner = game.checkWinner();
            if (winner != ' ') {
                std::cout << "Player " << winner << " wins!\n";
                break;
            }

            if (game.isBoardFull()) {
                std::cout << "It's a draw!\n";
                break;
            }
        }

    } while (true);

    return 0;
}
