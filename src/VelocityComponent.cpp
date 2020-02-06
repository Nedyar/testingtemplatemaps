#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(const uint32_t id, const float vx, const float vy, const float vz, const float spd)
    : velocityX{vx}, velocityY{vy}, velocityZ{vz}, speed{spd} {
    entityId = id;
}

VelocityComponent::~VelocityComponent() {

}

void VelocityComponent::resetAllVelocity() {
    velocityX = 0.f;
    velocityY = 0.f;
    velocityZ = 0.f;
}
