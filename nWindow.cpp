#include "nWindow.h"
#include <iostream>

nWindow::nWindow()
    : window(nullptr), renderer(nullptr) {}

nWindow::~nWindow() {
    Shutdown();
}

bool nWindow::Init() {
	bool success = true;

	//Initialize SDL
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("Nitocrys", 640, 480, 0);
		if (window == NULL)
		{
			SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}

        renderer = SDL_CreateRenderer(window,nullptr);
        if (renderer == NULL)
        {
            printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }

	}

	return success;
}

void nWindow::Clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void nWindow::Present() {
    SDL_RenderPresent(renderer);
}

void nWindow::Shutdown() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

SDL_Renderer* nWindow::GetRenderer() const {
    return renderer;
}
