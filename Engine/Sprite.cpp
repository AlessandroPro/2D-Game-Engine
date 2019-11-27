#include "Core.h"
#include "Sprite.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "AssetManager.h"

IMPLEMENT_DYNAMIC_CLASS(Sprite)

sf::Texture Sprite::findTexture(STRCODE guid)
{
	//texture = getAssetBySTRCODE(guid)->getTexture();
	return sf::Texture();
}

sf::Texture Sprite::findTexture(std::string guid)
{
	//texture = getAssetByGUID(guid)->getTexture();
	return sf::Texture();
}

void Sprite::initialize()
{
	if (textureAssetGUID_String != "" || textureAssetGUID_String != "\0")
	{
		findTexture(textureAssetGUID_String);
	}
	else
	{
		findTexture(textureAssetGUID_STRCODE);
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(dimensions); //might not be implementing this in later versions
	//sprite.setPosition(gameObject->getPosition());
	//sprite.setOrigin(gameObject->getPosition());
	Component::initialize();
}

void Sprite::update(float deltaTime)
{
	//sprite.setPosition(gameObject->getPosition());
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

void Sprite::setTextureAssetGUID(STRCODE guid)
{
	textureAssetGUID_STRCODE = guid;
}

void Sprite::setTextureAssetGUID(std::string guid)
{
	textureAssetGUID_String = guid;
}