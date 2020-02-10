#include "SituationComponent.hpp"

SituationComponent::SituationComponent(const uint32_t id, const float x, const float y, const float z, const float rot)
    : Component(id), x{x}, y{y}, z{z}, rotation{rot} {
}

SituationComponent::~SituationComponent() = default;

