#pragma once
#include "ISystem.h"
#include <iostream>
#include "TextComponent.h"

class TextSystem final : public ISystem
{
public:
	TextSystem(TextComponent* components);
	//Don't clean up the mTextComponents array
	//	the textcomponentmanager owns it and it's on the stack
	~TextSystem() = default;
	void Update(const float &deltaTime, const unsigned int &entityIndex) override;
private:
	TextComponent* mTextComponents[MAX_ENTITIES];
};