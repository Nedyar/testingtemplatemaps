#include <iostream>
using namespace std; 
#include "EntityManager.hpp"
#include "VelocityComponent.hpp"

int main() {
    EntityManager em;

    em.createComponent<VelocityComponent>(0);
    VelocityComponent& velocity = em.getComponent<VelocityComponent>(0);
    cout << "\n\n\n" << velocity.velocityX << endl;

    return 0;
}