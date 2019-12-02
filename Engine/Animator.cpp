#include "Core.h"
#include "RenderSystem.h"
#include "Animator.h"
#include "GameObject.h"

IMPLEMENT_DYNAMIC_CLASS(Animator)

void Animator::initialize()
{
	if (!isEnabled())
	{
		return;
	}
	Component::initialize();
}

void Animator::update(float deltaTime)
{
	if (!getGameObject()->isEnabled() || !enabled)
	{
		return;
	}

	if(RenderSystem::instance().getRenderWindow() == nullptr)
	{
		//Turn off all animations if the window is closed.
		for(auto animation : animations)
		{
			animation.second->stop();
		}
	}
}

void Animator::load(json::JSON& loadNode)
{
	Component::load(loadNode);

	if (loadNode.hasKey("Name"))
	{
		name = loadNode["Name"].ToString();
	}
}

Animator::Animator()
{
}

Animator::~Animator()
{
}

//may need better handling here?
void Animator::addAnimation(Animation* animation)
{
	animations.emplace(animation->name,animation);
}

void Animator::removeAnimation(Animation* animation)
{
	animations.erase(animation->name);
}

