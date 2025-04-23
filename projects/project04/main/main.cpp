#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "game.h"

void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, int x, int y) {
    SDL_Color white = { 255, 255, 255 };
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), white);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstRect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("AmazeGame",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 700, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\arial.ttf", 24); // Adjust path if needed

    bool quit = false;
    SDL_Event e;

    enum GameState { MENU, PLAYING, WIN };
    GameState state = MENU;
    Game game(1);
    int level = 1;
    Uint32 startTicks = 0;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            if (e.type == SDL_KEYDOWN) {
                if (state == MENU && e.key.keysym.sym == SDLK_RETURN) {
                    state = PLAYING;
                    game.reset(level);
                    startTicks = SDL_GetTicks();
                }
                else if (state == WIN && e.key.keysym.sym == SDLK_RETURN) {
                    level = 1;
                    game.reset(level);
                    state = PLAYING;
                    startTicks = SDL_GetTicks();
                }
                else if (state == PLAYING) {
                    switch (e.key.keysym.sym) {
                    case SDLK_UP: game.movePlayer(UP); break;
                    case SDLK_DOWN: game.movePlayer(DOWN); break;
                    case SDLK_LEFT: game.movePlayer(LEFT); break;
                    case SDLK_RIGHT: game.movePlayer(RIGHT); break;
                    case SDLK_ESCAPE: quit = true; break;
                    }
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        if (state == MENU) {
            renderText(renderer, font, "AMAZEGAME - PRESS ENTER TO BEGIN", 60, 280);
            renderText(renderer, font, "Use Arrow Keys to move. Paint all tiles!", 80, 320);
        }
        else if (state == PLAYING) {
            game.draw(renderer);

            Uint32 elapsed = (SDL_GetTicks() - startTicks) / 1000;
            renderText(renderer, font, "Level " + std::to_string(level), 10, 610);
            renderText(renderer, font, "Time: " + std::to_string(elapsed) + "s", 500, 610);
            renderText(renderer, font, "ESC to Quit", 250, 650);

            if (game.isComplete()) {
                if (level == 3) {
                    state = WIN;
                }
                else {
                    level++;
                    game.reset(level);
                    startTicks = SDL_GetTicks();
                }
            }
        }
        else if (state == WIN) {
            renderText(renderer, font, "CONGRATS! YOU BEAT ALL LEVELS!", 90, 280);
            renderText(renderer, font, "Press ENTER to play again", 140, 320);
        }

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
