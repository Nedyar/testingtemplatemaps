#include "EntityManager.hpp"

#include <iostream>
using namespace std;

void printVel(VelocityComponent &vel) {
    cout << "\n\t\t>Entity ID: " << (int)vel.id << endl;
    cout << "\t\t>Velocity X: " << vel.velocityX << endl;
    cout << "\t\t>Velocity Y: " << vel.velocityY << endl;
    cout << "\t\t>Velocity Z: " << vel.velocityZ << endl;
    cout << "\t\t>Speed: " << vel.speed << endl;
}

void printSit(SituationComponent &sit) {
    cout << "\n\t\t>Entity ID: " << (int)sit.id << endl;
    cout << "\t\t>Position X: " << sit.x << endl;
    cout << "\t\t>Position Y: " << sit.y << endl;
    cout << "\t\t>Position Z: " << sit.z << endl;
    cout << "\t\t>Rotation: " << sit.rotation << endl;
}

void printVector(EntityManager &em) {
    cout << "\nStorage:" << endl;
    cout << "\t<Velocities: ";
    for (auto &component : em.getComponents<VelocityComponent>())
        printVel(component);


    cout << "\n\t<Situations: ";
    for (auto &component : em.getComponents<SituationComponent>())
        printSit(component);
}

void creations(EntityManager &em) {
    cout << "CREATIONS" << endl;
    for (size_t i = 0; i < 4; ++i) {
        em.createComponent<VelocityComponent>(i);
        em.getComponent<VelocityComponent>(i).velocityX = i;
        em.getComponent<VelocityComponent>(i).velocityY = i;
        em.getComponent<VelocityComponent>(i).velocityZ = i;
        em.getComponent<VelocityComponent>(i).speed = i;
    }
    for (size_t i = 0; i < 4; ++i) {
        em.createComponent<SituationComponent>(i);
        em.getComponent<SituationComponent>(i).x = i;
        em.getComponent<SituationComponent>(i).y = i;
        em.getComponent<SituationComponent>(i).z = i;
        em.getComponent<SituationComponent>(i).rotation = i;
    }

    printVector(em);

    em.createComponent<SituationComponent>(0); // Esto peta porque ya existe la ID

    em.createComponent<SituationComponent>(1); // Esto peta porque ya existe la ID

    em.createComponent<SituationComponent>(2); // Esto peta porque ya existe la ID


    printVector(em);
}

void modifications(EntityManager &em) {
    cout << "MODIFICATIONS" << endl;
    printVector(em);

    for (size_t i = 0; i < 3; ++i) {
        em.getComponent<VelocityComponent>(i).velocityX = i + 15;
        em.getComponent<VelocityComponent>(i).velocityY = i + 34;
        em.getComponent<VelocityComponent>(i).velocityZ = i + 29;
        em.getComponent<VelocityComponent>(i).speed = i;
    }

    printVector(em);


    //em.getComponent<SituationComponent>(19); // Esto peta porque no existe la ID


    printVector(em);

}

void erases(EntityManager &em) {
    cout << "ERASES" << endl;
    printVector(em);

    em.eraseComponent<SituationComponent>(0);
    printVector(em);

    //em.eraseComponent<SituationComponent>(0); // Esto peta porque no existe la ID


    printVector(em);
}

int main() {
    EntityManager em;

    creations(em);
    modifications(em);
    em.createComponent<SituationComponent>(9813);
    em.createComponent<SituationComponent>(9813);
    em.createComponent<SituationComponent>(9813);
    em.createComponent<SituationComponent>(9813);

    erases(em);


    em.getComponent<SituationComponent>(9813).y = 999999;
    //em.createComponent<SituationComponent>(0);

    printVector(em);



    return 0;
}
