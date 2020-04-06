#include<iostream>
#include<SDL.h>
#include"SDLfinal.h"

using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Quang's first game";
struct BOX {
    int x;
    int y;
    int size = 10;
    int stepX = 0;
    int stepY = 0;
    void render(SDL_Renderer* renderer) {
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = size;
        filled_rect.h = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // green
        SDL_RenderFillRect(renderer, &filled_rect);
    }
    void move() {
        x += stepX;
        y += stepY;
    }
    void moveUp() {
        stepX = 0;
        stepY = -5;
    }
    void moveDown() {
        stepX = 0;
        stepY = 5;
    }
    void moveRight() {
        stepX = 5;
        stepY = 0;
    }
    void moveLeft() {
        stepX = -5;
        stepY = 0;
    }

    bool inside(int minX, int minY, int maxX, int maxY) {
        return (minX <= x && minY <= y && x + size <= maxX && y + size <= maxY) ? true : false;
    }
};
int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    //code here
    BOX box;
    box.x = 10;
    box.y = 10;
    while (box.inside(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)) {
        box.move();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white
        SDL_RenderClear(renderer);
        box.render(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(10);
        if (SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE: break;
            case SDLK_LEFT: box.moveLeft(); break;
            case SDLK_RIGHT: box.moveRight(); break;
            case SDLK_DOWN: box.moveDown(); break;
            case SDLK_UP: box.moveUp(); break;
            default: break;
            }
        }
    }
    //end code
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}