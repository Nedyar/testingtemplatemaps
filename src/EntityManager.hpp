#pragma once

#include <cstdint>
#include <unordered_map>

#include "Component.hpp"

class EntityManager {
public:

    EntityManager();
    ~EntityManager() = default;

    // las templates deben SIEMPRE definirse en el .hpp
    // esto es porque la T se convierte en "VelocityComponent" en tu caso
    // entonces si incluyes este archivo pero la plantilla no esta definida
    // el compilador no sabe ni cuantas funciones ni de que tipos va a tener que crearlas
    template <typename T>
    T  &getComponent(uint32_t id) {
        return components[typeid(T).name()][id];
    }

    template <typename T>
    void addComponent(uint32_t id) {
        components[typeid(T).name()].emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(id));
    }

    template <typename T>
    void eraseComponent(uint32_t id) {
        components[typeid(T).name()].erase(id);
    }

private:
    std::unordered_map<const char *, std::unordered_map<uint32_t, Component>> components;


};