#include "EntityManager.hpp"
#include "VelocityComponent.hpp"


EntityManager::EntityManager()
    : components{} {
    	components.emplace(std::piecewise_construct, std::forward_as_tuple(typeid(VelocityComponent).name()), std::forward_as_tuple());
}

EntityManager::~EntityManager() {}


template <typename T>
T  &EntityManager::getComponent(uint32_t id) {
    return components[typeid(T).name()][id];
};


template <typename T>
void EntityManager::addComponent(uint32_t id) {
    components[typeid(T).name()].emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(id));
};


template <typename T>
void  EntityManager::eraseComponent(uint32_t id) {
    components[typeid(T).name()].erase(id);
};