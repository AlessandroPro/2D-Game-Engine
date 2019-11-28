///-------------------------------------------------------------------------------------------------
// file: Animation.h
//
// author: Justin Hole
// date: 11/28/2019
//
// summary:	Component that animates a character onto the screen
///-------------------------------------------------------------------------------------------------
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#pragma once

#include "Sprite.h"
#include "Component.h"

class Animation: public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Animation, Component)

private:
	std::string animationName;
	time_t timeBeforeSpriteSwitch = 1; //a default value of 1 second is set, but it can be changed if the designer prefers a longer or shorter time between parts of an animation
	std::map<int, Sprite*> spritesInAnimation; //where int = order sprite is used in the animation

protected:
	void initialize() override;
	void update(float deltaTime) override;
	//orderInAnimation is a unique value that cannot be repeated. If it already exists in spritesInAnimation, the user's request to add a key-value
	//pair with a duplicate key is denied and a warning message is shown on the screen.
	bool isOrderNumberTaken(int orderInAnimation);
	//A sprite must be followed by another sprite and so on. There cannot be any gaps in the animation's play order of sprites. In addition, the first
	//sprite played in an animation must have an orderInAnimation number of 1. Therefore, sprites must be added to an animation (spritesInAnimation) one
	//by one with the first sprite added having an orderInAnimation of 1 and each additional sprite added incrementing this orderInAnimation by 1 to get
	//their own orderInAnimation.
	bool isOrderNumberSequential(int orderInAnimation);

	friend class Animator;

public:
	Animation();
	~Animation();
	void setAnimationName(std::string name) { animationName = name; }
	void setTimeBeforeSpriteSwitch(time_t seconds) { timeBeforeSpriteSwitch = seconds; }
	//The isOrderNumberTaken and isOrderNumberSequential methods are used to check the user input for validity before their new map entry is added.
	void addSpriteToAnimation(int orderInAnimation, Sprite* sprite);
	//All sprites following the sprite removed (in terms of animation order) have their orderInAnimation value decremented to ensure that no new gap
	//in the animation play order is created.
	void removeSpriteFromAnimation(int orderInAnimation);
};

#endif