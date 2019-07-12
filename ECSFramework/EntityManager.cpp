#include "EntityManager.h"
#include "EngineConstants.h"
#include "IComponentManager.h"
#include <exception>
#include <iostream>

EntityManager::~EntityManager()
{
	for (unsigned int i = 0; i < index; i++)
	{
		for (IComponentManager* cm : componentManagers)
		{
			cm->DeleteComponent(i);
		}
	}
}

unsigned int EntityManager::AddEntity()
{
	try
	{
		if (!freedEntities.empty())
		{
			int entityIndex = freedEntities.front();
			freedEntities.pop_front();
			return entityIndex;
		}

		if (index == MAX_ENTITIES)
		{
			throw std::exception("Reached entity limit!");
		}
		return index++;
	}
	catch (std::exception e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return INT_MAX;
	}
}

void EntityManager::DeleteEntity(unsigned int entity)
{
	freedEntities.push_back(entity);

	for (IComponentManager* cm : componentManagers)
	{
		cm->DeleteComponent(entity);
	}
}

void EntityManager::RegisterComponentManager(IComponentManager* componentManager)
{
	componentManagers.push_back(componentManager);
}

