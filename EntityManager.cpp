#include "EntityManager.h"
#include <algorithm> 

void EntityManager::AddEntity(nEntity* entity) {
    entities.push_back(entity);
}

void EntityManager::RemoveEntity(nEntity* entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
}

void EntityManager::UpdateAll(float dt) {
    for (auto entity : entities) {
        entity->Update(dt);
    }
}

void EntityManager::DrawAll(SDL_Renderer* renderer) {
    for (auto entity : entities) {
        entity->Draw(renderer);
    }
}

void EntityManager::ClearAll() {
    for (auto entity : entities) {
        delete entity;   
    }
    entities.clear();
}
