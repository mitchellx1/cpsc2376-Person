#include "game.h"

Game::Game(int lvl) {
    reset(lvl);
}

void Game::reset(int lvl) {
    level = lvl;
    if (level == 1) {
        rows = 6; cols = 6;
        makeLevel1();
    }
    else if (level == 2) {
        rows = 7; cols = 7;
        makeLevel2();
    }
    else if (level == 3) {
        rows = 9; cols = 9;
        makeLevel3();
    }
}

void Game::makeLevel1() {
    board = std::vector<std::vector<CellState>>(rows, std::vector<CellState>(cols, EMPTY));
    std::vector<Position> walls = {
        {0,5}, {1,5}, {2,5}, {3,5}, {4,5}, {5,5},
        {5,0}, {5,1}, {5,2}, {5,3}, {5,4},
        {0,2}, {1,2}, {3,3}, {4,3}
    };
    for (auto& w : walls) board[w.row][w.col] = WALL;
    playerPos = { 0, 0 };
    board[playerPos.row][playerPos.col] = PLAYER;
}

void Game::makeLevel2() {
    board = std::vector<std::vector<CellState>>(rows, std::vector<CellState>(cols, EMPTY));
    for (int i = 0; i < rows; i++) {
        board[i][0] = WALL;
        board[i][cols - 1] = WALL;
    }
    for (int j = 0; j < cols; j++) {
        board[0][j] = WALL;
        board[rows - 1][j] = WALL;
    }
    std::vector<Position> walls = { {1,4}, {2,4}, {2,2}, {4,1}, {4,2}, {4,4}, {5,4} };
    for (auto& w : walls) board[w.row][w.col] = WALL;
    playerPos = { 5,1 };
    board[playerPos.row][playerPos.col] = PLAYER;
}

void Game::makeLevel3() {
    board = std::vector<std::vector<CellState>>(rows, std::vector<CellState>(cols, EMPTY));
    for (int i = 0; i < rows; i++) {
        board[i][0] = WALL;
        board[i][cols - 1] = WALL;
    }
    for (int j = 0; j < cols; j++) {
        board[0][j] = WALL;
        board[rows - 1][j] = WALL;
    }
    std::vector<Position> walls = {
        {4,1}, {4,2}, {2,2}, {1,4}, {2,4}, {2,6}, {4,4}, {4,6}, {4,7},
        {5,4}, {6,2}, {6,3}, {6,4}, {6,5}, {6,6}
    };
    for (auto& w : walls) board[w.row][w.col] = WALL;
    playerPos = { 7,1 };
    board[playerPos.row][playerPos.col] = PLAYER;
}

void Game::draw(SDL_Renderer* renderer) {
    int tileSize = 640 / cols;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            SDL_Rect rect = { c * tileSize, r * tileSize, tileSize, tileSize };
            switch (board[r][c]) {
            case WALL: SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); break;
            case EMPTY: SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255); break;
            case PAINTED: SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); break;
            case PLAYER: SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); break;
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

void Game::movePlayer(Direction dir) {
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
        if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || board[newRow][newCol] == WALL) break;
        board[playerPos.row][playerPos.col] = PAINTED;
        playerPos = { newRow, newCol };
        board[playerPos.row][playerPos.col] = PLAYER;
    }
}

bool Game::isComplete() {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == EMPTY) return false;
        }
    }
    return true;
}
