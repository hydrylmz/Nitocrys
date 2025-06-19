#include "TimeManager.h"

TimeManager::TimeManager()
    : lastTime(SDL_GetTicks()), deltaTime(0.0f)
{
}

void TimeManager::Update()
{
    Uint64 currentTime = SDL_GetTicks();
    deltaTime = (currentTime - lastTime) / 1000.0f; // ms -> s
    lastTime = currentTime;
}

float TimeManager::GetDeltaTime() const
{
    return deltaTime;
}
