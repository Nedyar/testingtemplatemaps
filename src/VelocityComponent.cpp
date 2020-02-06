#include "VelocityComponent.hpp"

VelocityComponent::VelocityComponent(const uint32_t id, const float vx, const float vy, const float vz, const float spd)
    : Component(id), velocityX{vx}, velocityY{vy}, velocityZ{vz}, speed{spd} { }
// he hecho que Component inicialice id para que, si te olvidas algun override, Velocity siempre siempre, hereda de Component tanto atributos como funciones
// si Velocity no llama a Component y no tiene override en ninguno de sus metodos, entonces heredara solo los atributos (en tu caso heredaba id, pero no habia vtable)
VelocityComponent::~VelocityComponent() = default;

void VelocityComponent::resetAllVelocity() {
    velocityX = 0.f;
    velocityY = 0.f;
    velocityZ = 0.f;
}
