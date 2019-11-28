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
	//Checks if order number input entered by the player is an existing key in the spritesInAnimation map (used in the removeSpriteFromAnimation and
	//swapSpriteOrderInAnimation methods)
	bool doesOrderNumberExist(int orderInAnimation);

	friend class Animator;

public:
	Animation();
	~Animation();
	void setAnimationName(std::string name) { animationName = name; }
	void setTimeBeforeSpriteSwitch(time_t seconds) { timeBeforeSpriteSwitch = seconds; }
	//Adds a new entry to the spritesInAnimation map. The order number (integer key) of the new entry is the highest order number currently in the map
	//incremented by 1.
	void addSpriteToAnimation(Sprite* sprite);
	//Removes an entry from the spritesInAnimation map. All sprites following the sprite removed (in terms of animation order) have their 
	//orderInAnimation value decremented to ensure that no new gap in the animation play order is created.
	void removeSpriteFromAnimation(int orderInAnimation);
	//Swaps the order of two sprites in the animation
	void swapSpriteOrderInAnimation(int orderInAnimation1, int orderInAnimation2);
};

#endif