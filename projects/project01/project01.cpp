#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>

using namespace std;

enum CellState { EMPTY, WALL, PAINTED, PLAYER };
enum GameState { ONGOING, WIN, EXIT };
enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

struct Position {
    int row = 0;
    int col = 0;
};

//  Function Prototypes
void printBoard(const vector<vector<CellState>>& board);
void printRules();
void playGame(class AmazeGame& game);
bool askNextLevel(int& level);
void exitGame();

class AmazeGame {
private:
    vector<vector<CellState>> board;
    Position playerPos;
    int rows = 0, cols = 0;

public:
    AmazeGame(int level) {
        if (level == 1) {
            rows = 6;
            cols = 6;
            makeLevel1();
        }
        else if (level == 2) {
            rows = 7;
            cols = 7;
            makeLevel2();
        }
        else if (level == 3) {
            rows = 9;
            cols = 9;
            makeLevel3();
        }
    }

    void makeLevel1() {
        board = vector<vector<CellState>>(rows, vector<CellState>(cols, EMPTY));
        vector<Position> walls = {
            {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5},
            {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4},
            {0, 2}, {1, 2}, {3, 3}, {4, 3}
        };
        for (auto wall : walls) {
            board[wall.row][wall.col] = WALL;
        }
        playerPos = { 0, 0 };
        board[playerPos.row][playerPos.col] = PLAYER;
    }

    void makeLevel2() {
        board = vector<vector<CellState>>(rows, vector<CellState>(cols, EMPTY));

        for (int i = 0; i < rows; i++) {
            board[i][0] = WALL;
            board[i][cols - 1] = WALL;
        }
        for (int j = 0; j < cols; j++) {
            board[0][j] = WALL;
            board[rows - 1][j] = WALL;
        }

        vector<Position> walls = {
            {1,4}, {2,4}, {2,2}, {4,1}, {4,2}, {4,4}, {5,4}
        };
        for (auto wall : walls) {
            board[wall.row][wall.col] = WALL;
        }

        playerPos = { 5,1 };
        board[playerPos.row][playerPos.col] = PLAYER;
    }

    void makeLevel3() {
        board = vector<vector<CellState>>(rows, vector<CellState>(cols, EMPTY));

        for (int i = 0; i < rows; i++) {
            board[i][0] = WALL;
            board[i][cols - 1] = WALL;
        }
        for (int j = 0; j < cols; j++) {
            board[0][j] = WALL;
            board[rows - 1][j] = WALL;
        }

        vector<Position> walls = {
            {4,1}, {4,2}, {2,2}, {1,4}, {2,4}, {2,6}, {4,4}, {4,6}, {4,7}, {5,4}, {6,2}, {6,3},
        {6,4}, {6,5}, {6,6} };
        for (auto wall : walls) {
            board[wall.row][wall.col] = WALL;
        }

       
        playerPos = { 7,1 };
        board[playerPos.row][playerPos.col] = PLAYER;
    }

    GameState handleInput(char input) {
        if (input == 'q' || input == 'Q') {
            return EXIT;
        }
        Direction moveDir = NONE;
        if (input == -32) {
            input = _getch();
            switch (input) {
            case 72: moveDir = UP; break;
            case 80: moveDir = DOWN; break;
            case 75: moveDir = LEFT; break;
            case 77: moveDir = RIGHT; break;
            }
        }
        movePlayer(moveDir);
        return ONGOING;
    }

    void movePlayer(Direction dir) {
        if (dir == NONE) return;
        int dRow = 0, dCol = 0;
        switch (dir) {
        case UP: dRow = -1; break;
        case DOWN: dRow = 1; break;
        case LEFT: dCol = -1; break;
        case RIGHT: dCol = 1; break;
        default: return;
        }
        while (true) {
            int newRow = playerPos.row + dRow;
            int newCol = playerPos.col + dCol;
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || board[newRow][newCol] == WALL) {
                break;
            }
            board[playerPos.row][playerPos.col] = PAINTED;
            playerPos = { newRow, newCol };
            board[playerPos.row][playerPos.col] = PLAYER;
        }
    }

    GameState gameStatus() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == EMPTY) {
                    return ONGOING;
                }
            }
        }
        printBoard(board);
        return WIN;
    }

    const vector<vector<CellState>>& getBoard() const { return board; }
};

// Define printBoard function
void printBoard(const vector<vector<CellState>>& board) {
    system("cls");
    for (const auto& row : board) {
        for (const auto& cell : row) {
            switch (cell) {
            case EMPTY: cout << ". "; break;
            case WALL: cout << "# "; break;
            case PAINTED: cout << "* "; break;
            case PLAYER: cout << "O "; break;
            }
        }
        cout << endl;
    }
}

//  Define printRules function
void printRules() {
    cout << "Welcome to AMAZE!\n";
    cout << "Use arrow keys to move and paint every empty square.\n";
    cout << "Press 'q' to exit. The game ends when all squares are painted.\n";
    cout << "Press any key to start...\n";
    (void)_getch();
}

//  Handles the game loop
void playGame(AmazeGame& game) {
    while (game.gameStatus() == ONGOING) {
        printBoard(game.getBoard());
        char move = _getch();
        if (move == EOF) continue;
        game.handleInput(move);
    }

    cout << "\nCongratulations! You've painted the entire board!\n";
    cout << "Press any key to continue...\n";
    (void)_getch();
}

//  Handles level transitions
bool askNextLevel(int& level) {
    if (level <= 2) {
        cout << "Press 'n' for next level or 'q' to exit.\n";
        char choice = _getch();
        if (choice == 'q' || choice == 'Q') return false;
    }
    level++;

    if (level > 3) {
        return false;
    }

    return true;
}

//  Handles final game exit
void exitGame() {
    cout << "\nThanks for playing AMAZE!\n";
    cout << "Press any key to exit...\n";
    (void)_getch();
}

//  CLEANED-UP MAIN FUNCTION
int main() {
    int level = 1;
    bool firstTime = true;

    while (true) {
        AmazeGame game(level);

        if (firstTime) {
            printRules();
            firstTime = false;
        }

        playGame(game);

        if (!askNextLevel(level)) {
            break;
        }
    }

    exitGame();
    return 0;
}
