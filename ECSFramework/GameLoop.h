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
	bool Update(float deltaTime);

private:
	EntityManager entityManager;
	SystemManager systemManager;
	ComponentManager<TextComponent> textComponentManager;
};