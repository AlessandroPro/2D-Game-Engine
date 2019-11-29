#include "Core.h"
#include "Sprite.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "AssetManager.h"

IMPLEMENT_DYNAMIC_CLASS(Sprite)

Sprite::Sprite()
{

}

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

		if (textureNode.hasKey("ID"))
		{
			textureAssetID = textureNode["ID"].ToInt();
			//Load asset via asset manager
			//texture = AssetManager::instance().getAsset(textureAssetGUID);
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
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
	else
	{
		return;
	}

	sprite = new sf::Sprite(texture, dimensions);
}

void Sprite::initialize()
{
	Component::initialize();
}

void Sprite::update(float deltaTime)
{
	if(transform == nullptr)
	{
		transform = getGameObject()->getTransform();
	}
	sprite->setPosition(transform->getPosition());
}

void Sprite::render(sf::RenderWindow* _window)
{
	if(sprite != nullptr && 
		_window != nullptr)
	{
		_window->draw(*sprite);
	}
	
}

void Sprite::setImage(sf::Texture inTexture, sf::IntRect inDimensions)
{
	texture = inTexture;
	dimensions = inDimensions;
	bool validDimensions = true;

	//Check the dimensions of the texture against the requested sprite dimensions to see if it can actually map them
	if(texture.getSize().x < dimensions.left + dimensions.width ||
		texture.getSize().y < dimensions.top + dimensions.height)\
	{ 
		return;
	}

	sprite = new sf::Sprite(texture, dimensions);
}