#include "Core.h"
#include "Animation.h"

void Animation::initialize()
{
}

void Animation::update(float deltaTime)
{
}

bool Animation::doesOrderNumberExist(int orderInAnimation)
{
	for (auto& spriteInAnimation : spritesInAnimation)
	{
		if (spriteInAnimation.first == orderInAnimation)
		{
			return true;
		}
	}
	return false;
}

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::addSpriteToAnimation(Sprite* sprite)
{
	//A sprite must be followed by another sprite and so on. There cannot be any gaps in the animation's play order of sprites. In addition, the first
	//sprite played in an animation must have an order number of 1. Therefore, sprites must be added to an animation (spritesInAnimation) one
	//by one with the first sprite added having an orderInAnimation of 1 and each additional sprite added incrementing this order number by 1 to get
	//their own order number.
	int currentOrderNumber = 1;
	for (auto& spriteInAnimation : spritesInAnimation)
	{
		if (currentOrderNumber > spriteInAnimation.first)
		{
			//the order number is a unique value that cannot be repeated. If it already exists in spritesInAnimation, the user's request to add a 
			//key-value pair with a duplicate key is denied by the emplace map method.
			spritesInAnimation.emplace(currentOrderNumber, sprite);
		}
		else
		{
			currentOrderNumber++;
		}
	}
}

void Animation::removeSpriteFromAnimation(int orderInAnimation)
{
	if (doesOrderNumberExist(orderInAnimation))
	{
		spritesInAnimation.erase(orderInAnimation);
		for (auto& spriteInAnimation : spritesInAnimation)
		{
			if (spriteInAnimation.first > orderInAnimation)
			{
				int tempOrderNumber = spriteInAnimation.first;
				Sprite* tempSprite = spriteInAnimation.second;
				spritesInAnimation.erase(spriteInAnimation.first);
				spritesInAnimation.emplace(tempOrderNumber - 1, tempSprite);
			}
		}
	}
	else
	{
		LOG("The sprite you tried to remove with the given order number is not in the animation.")
	}
}

void Animation::swapSpriteOrderInAnimation(int orderInAnimation1, int orderInAnimation2)
{
	if (doesOrderNumberExist(orderInAnimation1) && doesOrderNumberExist(orderInAnimation2))
	{
		Sprite* tempSprite1 = spritesInAnimation[orderInAnimation1];
		Sprite* tempSprite2 = spritesInAnimation[orderInAnimation2];
		spritesInAnimation.erase(orderInAnimation1);
		spritesInAnimation.erase(orderInAnimation2);
		spritesInAnimation.emplace(orderInAnimation1, tempSprite2);
		spritesInAnimation.emplace(orderInAnimation2, tempSprite1);
	}
	else
	{
		LOG("One (or both) of the order numbers you entered does not exist (not a key for a sprite in the map for an animation).")
	}
}
