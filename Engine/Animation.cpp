#include "Core.h"
#include "Animation.h"

void Animation::initialize()
{
}

void Animation::update(float deltaTime)
{
}

bool Animation::isOrderNumberTaken(int orderInAnimation)
{
	return false;
}

bool Animation::isOrderNumberSequential(int orderInAnimation)
{
	return false;
}

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::addSpriteToAnimation(int orderInAnimation, Sprite* sprite)
{
}

void Animation::removeSpriteFromAnimation(int orderInAnimation)
{
}
