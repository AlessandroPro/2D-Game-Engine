#include "Core.h"
#include "Sprite.h"
#include "RenderSystem.h"

IMPLEMENT_DYNAMIC_CLASS(Sprite)

void Sprite::initialize()
{
	// This should be removed in the future

	//if (!texture.loadFromFile("../Assets/Front-Attack (1).png"))
	//{
	//	return;
	//}
	//sprite.setTexture(texture);
	//sprite.setPosition(sf::Vector2f(width * 0.5f, height * 0.5f));
	//sprite.setOrigin(sf::Vector2f(texture.getSize().x * 0.5f, texture.getSize().y * 0.5f));

	if (!texture.loadFromFile("../Assets/Dungeon.png"))
	{
		return;
	}
	sprite.setTexture(texture);
	int indexX = 0;
	int indexY = 0;
	sprite.setTextureRect(sf::IntRect(indexX * 64, indexY * 64, 64, 64));

	sprite.setPosition(sf::Vector2f(RenderSystem::instance().getWidth() * 0.5f, 
									RenderSystem::instance().getHeight() * 0.5f));
	sprite.setOrigin(sf::Vector2f(32, 32));
}

void Sprite::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}
