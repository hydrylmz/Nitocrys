#pragma once
#include <SDL3/SDL.h>

class TimeManager {
public:
    TimeManager();

    void Update();            // her frame �a��r
    float GetDeltaTime() const;  // frame aras� s�re (saniye)

private:
    Uint64 lastTime;
    float deltaTime;
};
