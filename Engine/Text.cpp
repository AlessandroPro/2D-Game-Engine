#include "Core.h"
#include "Text.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "AssetManager.h"

IMPLEMENT_DYNAMIC_CLASS(Text)

Text::Text()
{
}

Text::~Text()
{
	if (text != nullptr)
	{
		delete text;
	}
}

void Text::load(json::JSON& node)
{
}

void Text::initialize()
{
	Component::initialize();
}

void Text::update(float deltaTime)
{
	if (transform == nullptr)
	{
		transform = getGameObject()->getTransform();
	}
	text->setPosition(transform->getPosition());
}

void Text::render(sf::RenderWindow* _window)
{
	if (text != nullptr && _window != nullptr)
	{
		_window->draw(*text);
	}
}

void Text::setText(sf::Font inFont, std::string inString, int inCharacterSize, sf::Color inFillColor, sf::Text::Style inStyle)
{
}
