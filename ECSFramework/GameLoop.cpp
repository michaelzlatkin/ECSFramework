#include "GameLoop.h"
#include "TextComponent.h"
#include "TextSystem.h"
#include "IComponentManager.h"

GameLoop::GameLoop()
{
	//Initilization
	unsigned int text = entityManager.AddEntity();

	TextComponent textComponent;
	textComponent.text = "Hello world!\n";
	textComponentManager.AddComponent(text, textComponent);

	IComponentManager* abstractTextCompManager = &textComponentManager;

	entityManager.RegisterComponentManager(abstractTextCompManager);

	TextSystem* textSystem = new TextSystem(textComponentManager.GetComponents());

	systemManager.AddSystem(textSystem);
}

bool GameLoop::Update(float deltaTime)
{
	systemManager.UpdateSystems(deltaTime, entityManager.GetCurrentEntities());

	//For demonstration purposes this application will only run one tick and close
	//TODO: Implement SDL and messages to properly handle input
	//	This will make sure the program isn't stuck in an infinite loop without exit condition in a cleaner way
	return true;
}