#include "nWindow.h"
#include "InputManager.h"
#include "nTexture.h"

int main() {
    nWindow window;
    nTexture player;


    InputManager inputManager;

    if (!window.Init()) {
        return -1;
    }
    if (!player.Load(window.GetRenderer(), "Assets/Images/main.png")) {
        return -1;
    }
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            inputManager.HandleInput(&event);
        }

        window.Clear();                  // �nce ekran temizlenir
        player.Draw(window.GetRenderer(), 100, 100); // Sonra sprite �izilir
        window.Present();                // Son olarak ekrana yans�t�l�r
    }


    player.Unload();

    window.Shutdown();
    return 0;
}
