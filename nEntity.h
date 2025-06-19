#pragma once
#include <SDL3/SDL.h>
#include "nTexture.h"

class nEntity {
public:
    nEntity();

    void SetTexture(nTexture* tex);
    void SetPosition(float x, float y);
    void SetScale(float sx, float sy);
    void Move(float dx, float dy);

    virtual void Update(float dt);
    virtual void Draw(SDL_Renderer* renderer);

    virtual ~nEntity() = default;

protected:
    float x, y;
    float scaleX, scaleY;

    nTexture* texture;
};
