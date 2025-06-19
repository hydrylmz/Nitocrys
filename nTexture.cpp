#include "nTexture.h"
#include <iostream>
#include <SDL3_image/SDL_image.h>

nTexture::nTexture() : texture(nullptr), width(0), height(0) {}

nTexture::~nTexture() {
    Unload();
}

bool nTexture::Load(SDL_Renderer* renderer, const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cerr << "IMG_Load Error " << std::endl;
        return false;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_DestroySurface(surface);
        return false;
    }

    width = surface->w;
    height = surface->h;

    SDL_DestroySurface(surface);
    return true;
}

int nTexture::GetWidth() const {
    return width;
}

int nTexture::GetHeight() const {
    return height;
}

SDL_Texture* nTexture::GetRawTexture() const {
    return texture;
}

void nTexture::Draw(SDL_Renderer* renderer, int x, int y) {
    SDL_FRect dst = { (float)x, (float)y, (float)width, (float)height };
    SDL_RenderTexture(renderer, texture, nullptr, &dst);
}

void nTexture::Unload() {
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}
