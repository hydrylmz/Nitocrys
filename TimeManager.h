#pragma once
#include <SDL3/SDL.h>

class TimeManager {
public:
    TimeManager();

    void Update();            // her frame çaðýr
    float GetDeltaTime() const;  // frame arasý süre (saniye)

private:
    Uint64 lastTime;
    float deltaTime;
};
