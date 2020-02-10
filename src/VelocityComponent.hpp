#pragma once

#include "Component.hpp"

class VelocityComponent : public Component {
public:
    explicit VelocityComponent(uint32_t id, float vx = 100, float vy = 100, float vz = 100, float spd = 70);
    ~VelocityComponent() override; // si no hace override, heredas miembros, pero no hay vtable aunque Component tenga destructor virtualk
    

    void resetAllVelocity();

    float velocityX;
    float velocityY;
    float velocityZ;
    float speed;
    uint32_t speed2;
private:
};
