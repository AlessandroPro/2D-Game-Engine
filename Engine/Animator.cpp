#include "Core.h"
#include "Animator.h"
#include "GameObject.h"
#include "RenderSystem.h"

IMPLEMENT_DYNAMIC_CLASS(Animator)

void Animator::initialize()
{
	for(int animationID : animationIDs)
	{
		Animation* currentAnimation = (Animation*)getGameObject()->getComponent(animationID);

		if (currentAnimation != nullptr)
		{
			addAnimation(currentAnimation);
		}
	}
}

void Animator::update(float deltaTime)
{
	if(RenderSystem::instance().getRenderWindow() == nullptr)
	{
		//Turn off all animations if the window is closed.
		for(auto animation : animations)
		{
			animation.second->stop();
		}
	}
}

void Animator::load(json::JSON loadNode)
{
	Component::load(loadNode);

	if (loadNode.hasKey("Name"))
	{
		name = loadNode["Name"].ToString();
	}
	if(loadNode.hasKey("Animations"))
	{
		json::JSON animationsNode = loadNode["Animations"];
		for (auto& animationNode : animationsNode.ArrayRange())
		{
			if(animationNode.hasKey("ID"))
			{
				//Push back animation component IDs to load later during initialization
				//once the GUIDs have been loaded.
				animationIDs.push_back(animationNode["ID"].ToInt());
			}
		}
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

