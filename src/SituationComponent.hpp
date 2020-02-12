#pragma once

#include "Component.hpp"

class SituationComponent : public Component {
public:
    explicit SituationComponent(const uint32_t id, float x = 0, const float y = 0, const float z = 0, const float rot = 0);
    //SituationComponent(SituationComponent &c) = delete;
    
    ~SituationComponent();
    float x;
    float y;
    float z;
    float rotation;
private:
};
