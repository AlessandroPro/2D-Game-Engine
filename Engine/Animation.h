#pragma once
#include "Sprite.h"
#include "Component.h"

class Animation: public Component
{
private:
	std::string animationName;
	time_t timeBeforeSpriteSwitch = 1; //a default value of 1 second is set, but it can be changed if the designer prefers a longer or shorter time between parts of an animation
	std::map<int, Sprite*> spritesInAnimation; //where int = order sprite is used in the animation

protected:
	void initialize() override;
	void update(float deltaTime) override;

	friend class Animator;

public:
	Animation();
	~Animation();
};

