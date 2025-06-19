#include "Player.h"
#include <SDL3/SDL.h>

Player::Player(InputManager* inputManager)
    : speed(100.0f), input(inputManager)
{
    x = 260.0f;
    y = 200.0f;
    scaleX = scaleY = 0.2f;
}

void Player::Update(float dt)
{
    float dx = 0.0f;
    float dy = 0.0f;

    if (input->IsKeyDown(SDL_SCANCODE_W)) dy -= speed * dt;
    if (input->IsKeyDown(SDL_SCANCODE_S)) dy += speed * dt;
    if (input->IsKeyDown(SDL_SCANCODE_A)) dx -= speed * dt;
    if (input->IsKeyDown(SDL_SCANCODE_D)) dx += speed * dt;

    Move(dx, dy);
}
