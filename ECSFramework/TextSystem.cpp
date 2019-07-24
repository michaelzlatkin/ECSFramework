#include "TextSystem.h"
#include "TextComponent.h"

TextSystem::TextSystem(TextComponent * components) :
	mTextComponents{components}
{
}

void TextSystem::Update(const float &deltaTime, const unsigned int &entityIndex)
{
	for (unsigned int i = 0; i < entityIndex; i++)
	{
		if(mTextComponents[i])
		std::cout << mTextComponents[i]->mText;
	}
}
