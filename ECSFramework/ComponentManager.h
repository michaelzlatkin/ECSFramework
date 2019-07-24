#pragma once

#include "EngineConstants.h"

//TODO: ComponentManagerManager?

template <typename Component>
class ComponentManager
{
public:

	ComponentManager() = default;

	//Cleanup is done through the entry manager to minimize entry points
	~ComponentManager() = default;

	//Templated function so definition is in the header
	void AddComponent(unsigned int &ID, Component &component)
	{
		//This is faster than doing 'new', we make everything on the stack
		std::swap(mComponentArray[ID], component);
	}

	//We want to return a pointer so the user can feed it into their array of pointer constructor directly
	//This allows the system to make changes to the data in the components
	Component* GetComponents()
	{
		return &mComponentArray[0];
	}

private:
	Component mComponentArray[MAX_ENTITIES];
};