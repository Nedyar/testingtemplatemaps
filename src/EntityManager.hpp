#pragma once

#include <cstdint>
#include <unordered_map>

#include "Component.hpp"

class EntityManager {
public:

    EntityManager();
    ~EntityManager();

    template <typename T>
    T  &getComponent(uint32_t id);

    template <typename T>
    void addComponent(uint32_t id);

    template <typename T>
    void eraseComponent(uint32_t id);

private:
    std::unordered_map<const char *, std::unordered_map<uint32_t, Component>> components;


};