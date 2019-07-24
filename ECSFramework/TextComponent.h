#pragma once
#include <string>

//Components are strictly POD's in ECS
struct TextComponent
{
	std::string mText;
};