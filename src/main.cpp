#include "EntityManager.hpp"

#include <iostream>
using namespace std;

void printVel(VelocityComponent &vel) {
    cout << "\n\t\t>Entity ID: " << (int)vel.entityId << endl;
    cout << "\t\t>Velocity X: " << vel.velocityX << endl;
    cout << "\t\t>Velocity Y: " << vel.velocityY << endl;
    cout << "\t\t>Velocity Z: " << vel.velocityZ << endl;
    cout << "\t\t>Speed: " << vel.speed << endl;
    cout << "\t\t>Speed2: " << vel.speed2 << endl;
}

void printSit(SituationComponent &sit) {
    cout << "\n\t\t>Entity ID: " << (int)sit.entityId << endl;
    cout << "\t\t>Position X: " << sit.x << endl;
    cout << "\t\t>Position Y: " << sit.y << endl;
    cout << "\t\t>Position Z: " << sit.z << endl;
    cout << "\t\t>Rotation: " << sit.rotation << endl;
}

void printVector(EntityManager &em) {
    cout << "\nStorage:" << endl;
    cout << "\t<Velocities: ";
    for (auto &component : em.get<VelocityComponent>())
        printVel(component);


    cout << "\n\t<Situations: ";
    for (auto &component : em.get<SituationComponent>())
        printSit(component);
}

int main() {
    EntityManager em;

    printVector(em);

    em.create<SituationComponent>(0);
    em.create<SituationComponent>(1);
    em.create<SituationComponent>(0);


    em.create<VelocityComponent>(0);
    em.create<VelocityComponent>(1);
    em.create<VelocityComponent>(2);
    em.create<VelocityComponent>(2);
    em.create<VelocityComponent>(109);
    printVector(em);
    
    em.get<VelocityComponent>(2).velocityX = -4;
    em.get<VelocityComponent>(2).velocityY = 4;
    em.get<VelocityComponent>(2).velocityZ = 934;
    em.get<VelocityComponent>(2).speed = 1123;
    em.get<VelocityComponent>(2).speed2 = 124;
    printVector(em);

    em.erase<VelocityComponent>(1);
    em.erase<VelocityComponent>(0);
    em.erase<VelocityComponent>(-1);
    em.erase<VelocityComponent>(1090);


    printVector(em);

    em.get<int>();




    cout << ">Everithing was ok" << endl;


    return 0;
}
