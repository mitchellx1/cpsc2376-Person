#ifndef AMAZEGAME_H
#define AMAZEGAME_H

#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

enum CellState { EMPTY, WALL, PAINTED, PLAYER };
enum GameState { ONGOING, WIN, EXIT };
enum Direction { UP, DOWN, LEFT, RIGHT, NONE };

struct Position {
    int row = 0;
    int col = 0;
};

class AmazeGame {
private:
    vector<vector<CellState>> board;
    Position playerPos;
    int rows = 0, cols = 0;

public:
    AmazeGame(int level);
    void makeLevel1();
    void makeLevel2();
    void makeLevel3();
    GameState handleInput(char input);
    void movePlayer(Direction dir);
    GameState gameStatus();
    const vector<vector<CellState>>& getBoard() const;
};

// Function Prototypes
void printBoard(const vector<vector<CellState>>& board);
void printRules();
void playGame(AmazeGame& game);
void exitGame();

#endif
