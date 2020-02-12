#pragma once

#include "Storage.hpp"
#include "VelocityComponent.hpp"
#include "SituationComponent.hpp"

class EntityManager {
public:

    //////////////////////////////////////////////////
    //              THE RULE OF THE 3               //
    //////////////////////////////////////////////////

    explicit EntityManager();
    ~EntityManager();
    EntityManager(const EntityManager &em) = delete;

    //////////////////////////////////////////////////
    //                  GET COMPONENT               //
    //////////////////////////////////////////////////

    template <typename T>
    T  &getComponent(const uint32_t id) {
        auto &storage = getComponents<T>();
        return storage.at(storage.at(id));
    };

    template <typename T>
    Storage<T>  &getComponents() {
        static Storage<T> storage{255};
        return storage;
    };


    //////////////////////////////////////////////////
    //                CREATE COMPONENT              //
    //////////////////////////////////////////////////

    template <typename T>
    T &createComponent(const uint32_t id) {
        auto &storage = getComponents<T>();
        storage.emplace(id);
        return storage.at(storage.at(id));
    };


    //////////////////////////////////////////////////
    //                ERASE COMPONENT               //
    //////////////////////////////////////////////////

    template <typename T>
    void eraseComponent(const uint32_t id) {
        auto &storage = getComponents<T>();
        storage.erase(id);
    }
};