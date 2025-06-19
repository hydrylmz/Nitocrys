#pragma once
#include "nEntity.h"
#include "InputManager.h"

class Player : public nEntity {
public:
    Player(InputManager* inputManager);

    void Update(float dt) override;

private:
    float speed;
    InputManager* input;
};
