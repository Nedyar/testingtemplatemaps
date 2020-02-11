#pragma once

#include "unordered_map"
#include "ComponentStorage.hpp"
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
    //              	GET COMPONENTS              //
    //////////////////////////////////////////////////

    template <typename T>
    T  &getComponent(const uint32_t id) {
        const char *typeName = typeid(T).name();

        return static_cast<T &>(*componentMap[typeName][id]);

    };

    template <typename T>
    ComponentStorage<T>  &getComponents() {
        return *determinateStorage<T>();
    };


    //////////////////////////////////////////////////
    // 	              CREATE COMPONENT 				//
    //////////////////////////////////////////////////

    template <typename T>
    void createComponent(const uint32_t id) {
        const char *typeName = typeid(T).name();

        if (!componentMap[typeName].count(id)) {
            ComponentStorage<T> *storage = determinateStorage<T>();

            //if (storage) {
            Component *created_component = storage->emplace_back(id);

            if (created_component) {
                componentMap[typeName].emplace(std::piecewise_construct, std::forward_as_tuple(id), std::forward_as_tuple(created_component));
            }
            //}
        }
    };

    //////////////////////////////////////////////////
    // 	              ERASE COMPONENT 				//
    //////////////////////////////////////////////////

    template <typename T>
    void eraseComponent(const uint32_t id) {
        ComponentStorage<T> *storage = determinateStorage<T>();

        //if (storage) {
        const char *typeName = typeid(T).name();
        if (componentMap[typeName].count(id)) {
            Component *componentToDelete = componentMap[typeName][id];

            uint32_t idComponentMoved = storage->erase((T *)componentToDelete);
            componentMap[typeName][idComponentMoved] = componentToDelete;

            componentMap[typeName].erase(id);
        }
        //}
    }

private:

    //////////////////////////////////////////////////
    //       	COMPONENT TYPES DEFINITON 			//
    //////////////////////////////////////////////////

    template<typename T>
    ComponentStorage<T> *determinateStorage() {
        const char *typeName = typeid(T).name();

        if (typeName == typeid(VelocityComponent).name())
            return (ComponentStorage<T> *)velocitiesStorage;

        else if (typeName == typeid(SituationComponent).name())
            return (ComponentStorage<T> *)situationsStorage;

        return nullptr;
    }

    ComponentStorage<VelocityComponent> *velocitiesStorage;
    ComponentStorage<SituationComponent> *situationsStorage;
    unordered_map<const char *, unordered_map<uint32_t, Component *>> componentMap;

};