#include "EntityManager.hpp"
#include "VelocityComponent.hpp"

int main(void) {
    EntityManager em;

    em.addComponent<VelocityComponent>(0);

    return 0;
}