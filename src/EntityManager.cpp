#include "EntityManager.hpp"
#include "VelocityComponent.hpp"


EntityManager::EntityManager()
    : components{} {
    	components.emplace(std::piecewise_construct, std::forward_as_tuple(typeid(VelocityComponent).name()), std::forward_as_tuple());
}
