#include "GameLoop.h"
#include "TextComponent.h"
#include "TextSystem.h"

GameLoop::GameLoop()
{
	//Initilization
	unsigned int text = mEntityManager.AddEntity();

	TextComponent textComponent;
	textComponent.mText = "Hello world!\n";
	mTextComponentManager.AddComponent(text, textComponent);

	//It's ok to use new for the systems as we generally only create them at startup
	//We don't do that for components because we can add and should be able to add those whenever
	TextSystem* textSystem = new TextSystem(mTextComponentManager.GetComponents());

	mSystemManager.AddSystem(textSystem);
}

bool GameLoop::Update(const float &deltaTime)
{
	mSystemManager.UpdateSystems(deltaTime, mEntityManager.GetCurrentEntities());

	//For demonstration purposes this application will only run one tick and close
	//TODO: Implement SDL and messages to properly handle input
	//	This will make sure the program isn't stuck in an infinite loop without exit condition in a cleaner way
	return true;
}