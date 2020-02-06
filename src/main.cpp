#include "EntityManager.hpp"
#include "VelocityComponent.hpp"

int main() {
    EntityManager em;

    em.addComponent<VelocityComponent>(0);

    return 0;
}