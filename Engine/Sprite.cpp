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

}

void Sprite::load(json::JSON& node)
{
	Component::load(node);
	if (node.hasKey("Texture"))
	{
		json::JSON textureNode = node["Texture"];

		if (textureNode.hasKey("GUID"))
		{
			textureAssetGUID = textureNode["GUID"].ToInt();
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

	sprite = sf::Sprite(texture, dimensions);
}

void Sprite::initialize()
{
	Component::initialize();
}

void Sprite::update(float deltaTime)
{
	sf::Vector2f inPosition = getGameObject()->getTransform()->getPosition();
	sprite.setPosition(inPosition);
}

void Sprite::render(sf::RenderWindow* _window)
{
	_window->draw(sprite);
}

void Sprite::setImage(sf::Texture inTexture, sf::IntRect inDimensions)
{
	texture = inTexture;
	dimensions = inDimensions;
	sprite = sf::Sprite(texture, dimensions);
}