#include "Core.h"
#include "Sprite.h"
#include "GameObject.h"
#include "RenderSystem.h"

IMPLEMENT_DYNAMIC_CLASS(Sprite)

void Sprite::initialize()
{
	Component::initialize();
}

void Sprite::update(float deltaTime)
{
}

void Sprite::render(sf::RenderWindow* _window)
{
	_window->draw(sprite);
}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::setSpriteTexture(sf::Texture inTexture, sf::IntRect dimensions)
{
	sprite.setTexture(inTexture);
	sprite.setTextureRect(dimensions);
	//sprite.setPosition(gameObject->getPosition());
}