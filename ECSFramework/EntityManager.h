#pragma once
#include <list>

class IComponentManager;

class EntityManager
{
public:
	EntityManager() = default;
	~EntityManager();

	unsigned int AddEntity();

	void DeleteEntity(unsigned int entity);

	void RegisterComponentManager(IComponentManager* componentManager);

	unsigned int GetCurrentEntities() { return index; };

private:
	std::list<unsigned int> freedEntities;

	//TODO: Implement observer pattern to limit dependencies like these?
	std::list<IComponentManager*> componentManagers;
	unsigned int index = 0;

	//Rule of 5
	EntityManager(const EntityManager &other) = delete;
	EntityManager(EntityManager &&other) = delete;
	EntityManager operator=(const EntityManager &other) = delete;
	EntityManager operator=(EntityManager &&other) = delete;
};