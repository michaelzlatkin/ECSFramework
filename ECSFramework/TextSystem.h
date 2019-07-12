#pragma once
#include "ISystem.h"
#include <iostream>
#include "TextComponent.h"

class TextSystem : public ISystem
{
public:
	TextSystem(TextComponent** components);
	void Update(float deltaTime, unsigned int entityIndex) override;
private:
	//CRITICAL TODO: Move data out of the system, this is NOT congruent with ECS!
	TextComponent* textComponents[MAX_ENTITIES];

	//Rule of 5
	TextSystem(const TextSystem &other) = delete;
	TextSystem(TextSystem &&other) = delete;
	TextSystem operator=(const TextSystem &other) = delete;
	TextSystem operator=(TextSystem &&other) = delete;
};