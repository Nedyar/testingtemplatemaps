#pragma once

#include <stdint.h>

class Component {
public:
    virtual ~Component() = default;
    uint32_t entityId;
protected:
};
