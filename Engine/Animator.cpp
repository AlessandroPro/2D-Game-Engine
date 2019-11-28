#include "Core.h"
#include "Animator.h"

void Animator::initialize()
{
}

void Animator::update(float deltaTime)
{
}

Animator::Animator()
{
}

Animator::~Animator()
{
}

void Animator::addAnimation(Animation* animation)
{
	animations.push_back(animation);
}

void Animator::removeAnimation(Animation* animation)
{
	animations.remove(animation);
}
