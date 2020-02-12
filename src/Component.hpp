#pragma once

#include <cstdint>

class Component {
public:
    explicit Component(uint32_t _id) : id(_id) { } // velocity no heredaba de Component porque no hacia nada con el, por poner algo he hecho que este valor lo inicialice el padre
    virtual ~Component() = default; // velocity ahora hace override de este metodo (no lo hacia antes, y asi sabemos que sí hereda)
    uint32_t id { };
protected:
};
