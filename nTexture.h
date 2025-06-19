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

    int GetWidth() const;
    int GetHeight() const;
    SDL_Texture* GetRawTexture() const;

private:
    SDL_Texture* texture;
    int width, height;

};
