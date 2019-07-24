#pragma once
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include "TextComponent.h"

class GameLoop
{
public:
	GameLoop();
	~GameLoop() = default;

	//if true, we exit the application
	bool Update(const float &deltaTime);

private:
	EntityManager mEntityManager;
	SystemManager mSystemManager;
	ComponentManager<TextComponent> mTextComponentManager;
};