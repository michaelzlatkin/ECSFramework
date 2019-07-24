#pragma once
#include <list>

class EntityManager final
{
public:
	EntityManager() = default;

	unsigned int AddEntity();

	void DeleteEntity(unsigned int &entity);

	const unsigned int GetCurrentEntities() { return mIndex; };

private:
	std::list<unsigned int> mFreedEntities;

	unsigned int mIndex = 0;
};