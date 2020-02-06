#pragma once

#include "Component.hpp"

class VelocityComponent : public Component {
public:
    VelocityComponent(const uint32_t id, const float vx = 0, const float vy = 0, const float vz = 0, const float spd = 70);
    ~VelocityComponent();
    

    void resetAllVelocity();

    float velocityX;
    float velocityY;
    float velocityZ;
    float speed;
private:
};
