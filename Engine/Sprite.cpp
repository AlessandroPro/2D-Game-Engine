#include "Core.h"
#include "Sprite.h"
#include "GameObject.h"
#include "AssetManager.h"
#include "TextureAsset.h"

IMPLEMENT_DYNAMIC_CLASS(Sprite)

Sprite::~Sprite()
{
	if(sprite != nullptr)
	{
		delete sprite;
	}
}

void Sprite::load(json::JSON& node)
{
	Component::load(node);
	if (node.hasKey("Texture"))
	{
		json::JSON textureNode = node["Texture"];
		if (textureNode.hasKey("textureAssetGUID"))
		{
			textureAssetGUID = textureNode["textureAssetGUID"].ToString();
			textureAssetID = GUIDToSTRCODE(textureAssetGUID);
		}
	}
	if(node.hasKey("Dimensions"))
	{
		float w, h, t, l = 0.0f;
		json::JSON dimensionNode = node["Dimensions"];

		if(!dimensionNode.hasKey("Left") ||
			!dimensionNode.hasKey("Top") ||
			!dimensionNode.hasKey("Width") ||
			!dimensionNode.hasKey("Height"))
		{
			return;
		}

		l = dimensionNode["Left"].ToFloat();
		t = dimensionNode["Top"].ToFloat();
		w = dimensionNode["Width"].ToFloat();
		h = dimensionNode["Height"].ToFloat();
		
		dimensions = sf::IntRect(l,t,w,h);
	}
}

void Sprite::initialize()
{
	Component::initialize();
	TextureAsset* asset = dynamic_cast<TextureAsset*>(AssetManager::instance().GetAssetBySTRCODE(textureAssetID));
	if (asset == nullptr || 
		(dimensions.left == dimensions.top &&
		dimensions.top == dimensions.width &&
		dimensions.width == dimensions.height &&
		dimensions.height == 0))
	{
		asset = static_cast<TextureAsset*>(AssetManager::instance().GetDefaultAssetOfType("TextureAsset"));
		sprite = new sf::Sprite(asset->getTexture());
	}
	else
	{
		sprite = new sf::Sprite(asset->getTexture(),dimensions);
	}
}

void Sprite::update(float deltaTime)
{
	sprite->setPosition(getGameObject()->getTransform()->getPosition());
}

void Sprite::render(sf::RenderWindow* _window)
{
	if(sprite != nullptr && _window != nullptr && isEnabled())
	{
		_window->draw(*sprite);
	}
}

void Sprite::setImage(sf::Texture inTexture, sf::IntRect inDimensions)
{
	dimensions = inDimensions;

	//Check the dimensions of the texture against the requested sprite dimensions to see if it can actually map them
	if(inTexture.getSize().x < (dimensions.left + dimensions.width) ||
		inTexture.getSize().y < (dimensions.top + dimensions.height))
	{ 
		return;
	}

	sprite->setTexture(inTexture);
	sprite->setTextureRect(inDimensions);
}