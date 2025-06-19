#include "nWindow.h"
#include "InputManager.h"
#include "nTexture.h"
#include "Player.h"
#include "TimeManager.h"

int main() {
    nWindow window;
    nTexture playerTex;
    InputManager inputManager;
    TimeManager timeManager;

    if (!window.Init()) return -1;

    if (!playerTex.Load(window.GetRenderer(), "Assets/Images/main.png")) return -1;

    Player player(&inputManager);
    player.SetTexture(&playerTex);

    bool running = true;
    SDL_Event event;

    while (running) {
        timeManager.Update();
        float dt = timeManager.GetDeltaTime();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
            inputManager.HandleInput(&event);
        }

        player.Update(dt);

        window.Clear();
        player.Draw(window.GetRenderer());
        window.Present();
    }

    window.Shutdown();
    return 0;
}
