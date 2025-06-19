#pragma once
#include <vector>
#include "nEntity.h"

class EntityManager {
public:
    void AddEntity(nEntity* entity);
    void RemoveEntity(nEntity* entity);

    void UpdateAll(float dt);
    void DrawAll(SDL_Renderer* renderer);

    void ClearAll();

private:
    std::vector<nEntity*> entities;
};
