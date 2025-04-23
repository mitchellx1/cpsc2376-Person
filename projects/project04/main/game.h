#pragma once
#include <SDL2/SDL.h>
#include <vector>

enum CellState { EMPTY, WALL, PAINTED, PLAYER };
enum Direction { NONE, UP, DOWN, LEFT, RIGHT };

struct Position {
    int row, col;
};

class Game {
public:
    Game(int level);
    void reset(int level);
    void draw(SDL_Renderer* renderer);
    void movePlayer(Direction dir);
    bool isComplete();

private:
    int rows, cols;
    int level;
    Position playerPos;
    std::vector<std::vector<CellState>> board;

    void makeLevel1();
    void makeLevel2();
    void makeLevel3();
};
