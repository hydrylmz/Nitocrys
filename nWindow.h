#pragma once
#include <SDL3/SDL.h>
#include <string>

class nWindow {
public:
    nWindow();
    ~nWindow();

    bool Init();
    void Clear();
    void Present();
    void Shutdown();

    SDL_Renderer* GetRenderer() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
