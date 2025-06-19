#include "nEntity.h"

nEntity::nEntity() : x(0), y(0), scaleX(1.0f), scaleY(1.0f), texture(nullptr) {}

void nEntity::SetTexture(nTexture* tex) {
    texture = tex;
}

void nEntity::SetPosition(float px, float py) {
    x = px;
    y = py;
}

void nEntity::SetScale(float sx, float sy) {
    scaleX = sx;
    scaleY = sy;
}


void nEntity::Update(float dt) {

}


void nEntity::Move(float dx, float dy) {
    x += dx;
    y += dy;
}


void nEntity::Draw(SDL_Renderer* renderer) {
    if (texture) {
        int w = texture->GetWidth();
        int h = texture->GetHeight();

        SDL_FRect dst = {
            x,
            y,
            w * scaleX,
            h * scaleY
        };

        SDL_RenderTexture(renderer, texture->GetRawTexture(), nullptr, &dst);
    }
}

