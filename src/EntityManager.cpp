#include "EntityManager.hpp"


EntityManager::EntityManager()
	{
		velocitiesStorage = new ComponentStorage<VelocityComponent>(255);
		situationsStorage = new ComponentStorage<SituationComponent>(255);
}

EntityManager::~EntityManager() {
	delete velocitiesStorage;
	delete situationsStorage;
}
