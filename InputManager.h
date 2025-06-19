#pragma once
#include <SDL3/SDL_events.h>
class InputManager
{
public:
	void HandleInput(const SDL_Event* e);
	bool IsKeyDown(SDL_Scancode key);



};

