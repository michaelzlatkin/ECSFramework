#include "TextSystem.h"
#include "TextComponent.h"

TextSystem::TextSystem(TextComponent ** components) :
	textComponents{*components}
{
}

void TextSystem::Update(float deltaTime, unsigned int entityIndex)
{
	for (int i = 0; i < entityIndex; i++)
	{
		if(textComponents[i])
		std::cout << textComponents[i]->text;
	}
}
