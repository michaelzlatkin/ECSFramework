#pragma once

#include "EngineConstants.h"
#include "IComponentManager.h"

//TODO: ComponentManagerManager?

template <class Component>
class ComponentManager : public IComponentManager
{
public:

	ComponentManager() = default;

	//Cleanup is done through the entry manager to minimize entry points
	~ComponentManager() = default;

	//Templated function so definition is in the header
	void AddComponent(unsigned int ID, Component &component)
	{
		componentArray[ID] = new Component{ component };
	}

	void DeleteComponent(unsigned int ID) override
	{
		//We have a EntityManager::freedEntities which we can use to not do this check, but this is faster than
		//doing std::find on a list for every entity created for every componentManager
		if (componentArray[ID])
		{
			delete componentArray[ID];
			componentArray[ID] = nullptr;
		}
	}

	//We want to return a pointer to a pointer so the user can feed it into their array of pointer constructor directly
	Component** GetComponents()
	{
		return componentArray;
	}

private:
	Component* componentArray[MAX_ENTITIES];

	//Rule of 5
	ComponentManager(const ComponentManager &other) = delete;
	ComponentManager(ComponentManager &&other) = delete;
	ComponentManager operator=(const ComponentManager &other) = delete;
	ComponentManager operator=(ComponentManager &&other) = delete;
};