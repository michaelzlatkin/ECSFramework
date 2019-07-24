#include "EntityManager.h"
#include "EngineConstants.h"
#include <exception>
#include <iostream>

unsigned int EntityManager::AddEntity()
{
	try
	{
		if (!mFreedEntities.empty())
		{
			int entityIndex = mFreedEntities.front();
			mFreedEntities.pop_front();
			return entityIndex;
		}

		if (mIndex == MAX_ENTITIES)
		{
			throw std::exception("Reached entity limit!");
		}
		return mIndex++;
	}
	catch (std::exception e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return INT_MAX;
	}
}

void EntityManager::DeleteEntity(unsigned int &entity)
{
	mFreedEntities.push_back(entity);
}
