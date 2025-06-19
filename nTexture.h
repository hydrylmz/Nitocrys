#pragma once
#include <SDL3/SDL.h>
#include <string>

class nTexture {
public:
    nTexture();
    ~nTexture();

    bool Load(SDL_Renderer* renderer, const std::string& path);
    void Draw(SDL_Renderer* renderer, int x, int y);
    void Unload();

private:
    SDL_Texture* texture;
    int width, height;
};
