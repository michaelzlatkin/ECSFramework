#pragma once
#include "EngineConstants.h"
#include "ISystem.h"

class SystemManager final
{
public:
	SystemManager() = default;

	virtual ~SystemManager();

	void AddSystem(ISystem* system);

	//We pass along the entityIndex so we don't do a lot of checks for nullptrs unnecessarily
	void UpdateSystems(float deltaTime, unsigned int entityIndex);
	
private:
	ISystem* systems[MAX_SYSTEMS];
	int index;

	//Rule of 5
	SystemManager(const SystemManager &other) = delete;
	SystemManager(SystemManager &&other) = delete;
	SystemManager operator=(const SystemManager &other) = delete;
	SystemManager operator=(SystemManager &&other) = delete;
};