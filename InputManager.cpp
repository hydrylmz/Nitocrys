#include "InputManager.h"
#include <SDL3/SDL_assert.h>
#include <iostream>

bool InputManager::IsKeyDown(SDL_Scancode key) {
    const bool* keyboardState = SDL_GetKeyboardState(nullptr);  
    return keyboardState[key];
}
    

void InputManager::HandleInput(const SDL_Event* e)
{
    if (e->type != SDL_EVENT_KEY_DOWN) {
        return;
    }
    if (e->key.scancode == SDL_SCANCODE_W) {
        std::cout << "W basýlý tutuluyor\n";
    }
    else if (e->key.scancode == SDL_SCANCODE_S) {
        std::cout << "S basýlý tutuluyor\n";
    }
}