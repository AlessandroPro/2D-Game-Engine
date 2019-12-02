#include "Core.h"
#include "AssetManager.h"
#include "Animator.h"
#include "GameObject.h"
#include "TextureAsset.h"
#include "Sprite.h"
#include "Animation.h"

IMPLEMENT_DYNAMIC_CLASS(Animation)

Animation::Animation()
{

}

Animation::~Animation()
{
	Animator* currentAnimator = dynamic_cast<Animator*>(getGameObject()->getComponent("Animator"));
	if (currentAnimator != nullptr)
	{
		currentAnimator->removeAnimation(this);
	}

}

void Animation::load(json::JSON& loadNode)
{
	Component::load(loadNode);

	if (loadNode.hasKey("Name"))
	{
		name = loadNode["Name"].ToString();
	}

	if (loadNode.hasKey("Speed"))
	{
		speed = loadNode["Speed"].ToFloat();
	}
	if (loadNode.hasKey("Frames"))
	{
		json::JSON framesNode = loadNode["Frames"];
		for (auto& frameNode : framesNode.ArrayRange())
		{
			if (!frameNode.hasKey("Left") ||
				!frameNode.hasKey("Top") ||
				!frameNode.hasKey("Width") ||
				!frameNode.hasKey("Height"))
			{
				continue;
			}
			frames.push_back(sf::IntRect(frameNode["Left"].ToInt(), frameNode["Top"].ToInt(), frameNode["Width"].ToInt(), frameNode["Height"].ToInt()));
		}
	}
	if (loadNode.hasKey("Texture"))
	{
		json::JSON textureNode = loadNode["Texture"];
		if (textureNode.hasKey("textureAssetGUID"))
		{
			textureGUID = textureNode["textureAssetGUID"].ToString();
			spriteSheetID = GUIDToSTRCODE(textureGUID);
		}
	}

	if (loadNode.hasKey("Loopable"))
	{
		isLoopable = loadNode["Loopable"].ToBool();
	}
}

void Animation::setEnabled(bool _enabled)
{
	enabled = _enabled;
	if (enabled && getGameObject()->isEnabled() && !initialized)
	{
		initialize();
	}
}

void Animation::initialize()
{
	if (!isEnabled())
	{
		return;
	}

	Component::initialize();
	static_cast<Animator*>(getGameObject()->getComponent("Animator"))->addAnimation(this);
	asset = dynamic_cast<TextureAsset*>(AssetManager::instance().GetAssetBySTRCODE(spriteSheetID));
	if (asset == nullptr)
	{
		getGameObject()->removeComponent(this->id);
		return;
	}
	sprite = dynamic_cast<Sprite*>(getGameObject()->getComponent("Sprite"));
	if (sprite == nullptr)
	{
		getGameObject()->removeComponent(this->id);
	}
}

void Animation::play()
{
	isPlaying = true;
	currentSpriteIndex = 0;
	timeSinceLastFrame = 0;
	sprite->setImage(asset->getTexture(), frames[currentSpriteIndex]);
}

void Animation::update(float deltaTime)
{
	if (!getGameObject()->isEnabled() || !enabled)
	{
		return;
	}
	if (isPlaying && sprite != nullptr && asset != nullptr)
	{
		timeSinceLastFrame += deltaTime;

		//If the most recent iteration of the clock() is greater than the frame switching speed
		//then the frame is updated for the animation
		if (timeSinceLastFrame > speed)
		{
			currentSpriteIndex++;

			//Behaviour for reaching the end of the clip
			if (currentSpriteIndex >= frames.size())
			{
				if (isLoopable)
				{
					currentSpriteIndex = 0;
				}
				else
				{
					isPlaying = false;
					return;
				}
			}
			timeSinceLastFrame = 0;
			sprite->setImage(asset->getTexture(), frames[currentSpriteIndex]);
		}

	}
}