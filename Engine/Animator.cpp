#include "Core.h"
#include "Animator.h"

IMPLEMENT_DYNAMIC_CLASS(Animator)

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
	animations.emplace(animation->name,animation);
}

void Animator::removeAnimation(Animation* animation)
{
	animations.erase(animation->name);
}
