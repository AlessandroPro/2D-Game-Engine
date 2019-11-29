#include "Core.h"
#include "Animation.h"

IMPLEMENT_DYNAMIC_CLASS(Animation)

void Animation::initialize()
{
	currentSpriteIndex = 0;
}

void Animation::update(float deltaTime)
{
	if(isPlaying && sprite != nullptr)
	{
		if(timeClipChanged < 0)
		{
			timeClipChanged = time(0);
			return;
		} 

		if(difftime(time(0), timeClipChanged) > speed)
		{
			currentSpriteIndex++;
			timeClipChanged = time(0);
			if (currentSpriteIndex >= frames.size())
			{
				if (isLoopable)
				{
					currentSpriteIndex = 0;
				}
				else
				{
					isPlaying = false;
					timeClipChanged = -1;
					return;
				}
			}

			sprite->setImage(spriteSheet,frames[currentSpriteIndex]);
		}
		
	}
}


Animation::Animation()
{
}

Animation::~Animation()
{
}