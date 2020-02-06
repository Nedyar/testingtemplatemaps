#pragma once

#include "Component.hpp"

class VelocityComponent : public Component {
public:
    explicit VelocityComponent(uint32_t id, float vx = 0, float vy = 0, float vz = 0, float spd = 70);
    ~VelocityComponent() override; // si no hace override, heredas miembros, pero no hay vtable aunque Component tenga destructor virtualk
    

    void resetAllVelocity();

    float velocityX;
    float velocityY;
    float velocityZ;
    float speed;
private:
};
