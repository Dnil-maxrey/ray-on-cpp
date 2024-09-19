#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* win = NULL;
SDL_Surface* scr = NULL;
SDL_Surface* smile = NULL;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    win = SDL_CreateWindow("Main не резиновый", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        return 1;
    }

    scr = SDL_GetWindowSurface(win);

    return 0;
}

int load() {
    smile = SDL_LoadBMP("smile.bmp");

    if (smile == NULL) {
        return 1;
    }

    return 0;
}

void quit() {
    SDL_FreeSurface(smile);

    SDL_DestroyWindow(win);

    SDL_Quit();
}

int main(int argc, char** args) {
    if (init() == 1) {
        return 1;
    }

    if (load() == 1) {
        return 1;
    }

    SDL_BlitSurface(smile, NULL, scr, NULL);

    SDL_UpdateWindowSurface(win);

    SDL_Delay(2000);

    quit();

    return 0;
};