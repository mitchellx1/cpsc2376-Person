#include <iostream>
#include <vector>
#include <conio.h>  // For _getch()
#include <cstdlib>
#include <ctime>

using namespace std;

enum class CellState { EMPTY, WALL, PAINTED, PLAYER };
enum class GameState { ONGOING, WIN, EXIT };

struct Position {
    int row = 0;
    int col = 0;
};

class AmazeGame {
private:
    vector<vector<CellState>> board;
    Position playerPos = { 0, 0 };
    int rows = 0;
    int cols = 0;

public:
    AmazeGame(int level) {
        if (level == 1) {
            rows = 6;
            cols = 6;
            makeLevel1();
        }
    }

    void makeLevel1() {
        board = vector<vector<CellState>>(rows, vector<CellState>(cols, CellState::EMPTY));

        vector<Position> walls = {
            {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5},
            {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4},
            {0, 2}, {1, 2}, {3, 3}, {4, 3}
        };
        for (auto wall : walls) {
            board[wall.row][wall.col] = CellState::WALL;
        }

        playerPos = { 0, 0 };
        board[playerPos.row][playerPos.col] = CellState::PLAYER;
    }

    void printBoard() {
        system("cls");
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                switch (board[i][j]) {
                case CellState::EMPTY: cout << ". "; break;
                case CellState::WALL: cout << "# "; break;
                case CellState::PAINTED: cout << "* "; break;
                case CellState::PLAYER: cout << "O "; break;
                }
            }
            cout << endl;
        }
    }

    void play(GameState& result) {
        printRules();
        GameState state = GameState::ONGOING;

        while (state == GameState::ONGOING) {
            printBoard();
            char move = _getch();
            if (move == EOF) continue;
            state = handleInput(move);
            if (state == GameState::EXIT) {
                result = GameState::EXIT;
                return;
            }
            state = gameStatus();
        }

        cout << "\nCongratulations! You've painted the entire board!\n";
        result = GameState::WIN;
    }

    void printRules() {
        cout << "Welcome to AMAZE!\n";
        cout << "Use arrow keys to move the ball and paint every empty square.\n";
        cout << "Press 'q' at any time to exit the game.\n";
        cout << "The game ends when all squares are painted. Avoid the walls!\n";
        cout << "Press any key to start...\n";
        _getch();
    }

    GameState handleInput(char input) {
        int dRow = 0, dCol = 0;

        if (input == 'q' || input == 'Q') {
            return GameState::EXIT;
        }

        if (input == -32) {
            input = _getch();
            switch (input) {
            case 72: dRow = -1; break;
            case 80: dRow = 1; break;
            case 75: dCol = -1; break;
            case 77: dCol = 1; break;
            }
        }

        movePlayer(dRow, dCol);
        return GameState::ONGOING;
    }

    void movePlayer(int dRow, int dCol) {
        if (dRow == 0 && dCol == 0) return;

        while (true) {
            int newRow = playerPos.row + dRow;
            int newCol = playerPos.col + dCol;

            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || board[newRow][newCol] == CellState::WALL) {
                break;
            }

            board[playerPos.row][playerPos.col] = CellState::PAINTED;
            playerPos = { newRow, newCol };
            board[playerPos.row][playerPos.col] = CellState::PLAYER;
            printBoard();
        }
    }

    GameState gameStatus() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == CellState::EMPTY) {
                    return GameState::ONGOING;
                }
            }
        }
        return GameState::WIN;
    }
};

int main() {
    GameState result;

    AmazeGame game1(1);
    game1.play(result);

    cout << "\nThanks for playing AMAZE!\n";
    return 0;
}
