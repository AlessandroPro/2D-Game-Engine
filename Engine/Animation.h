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
	std::string name = "";
	float speed = 1.0f;
	clock_t timeSinceLastFrame = -1;
	sf::Texture spriteSheet;
	std::vector<sf::IntRect> frames;
	STRCODE spriteSheetID = -1;
	STRCODE spriteID = -1;
	Sprite* sprite = nullptr;
	int currentSpriteIndex = -1;
	bool isPlaying = false;
	bool isLoopable = false;

protected:
	void initialize() override;
	void update(float deltaTime) override;
	void play() { isPlaying = true; }
	void stop() 
	{ 
		isPlaying = false; 
		timeSinceLastFrame = -1;
	}

	friend class Animator;

public:
	Animation();
	~Animation();
	std::string& getName() { return name; }
	void setName(std::string inName) { name = inName; }
	void setSpeed(time_t inSpeed) { speed = inSpeed; }
	void setFrames(std::vector<sf::IntRect> inFrames) { frames = inFrames; }
	void setLoopingStatus(bool inLoopable) { isLoopable = inLoopable; }
	void setSprite(Sprite* inSprite) {
		sprite = inSprite;
		spriteID = sprite->getID();
	}
	void setSpriteSheet(sf::Texture inSpriteSheet, STRCODE inID) 
	{ 
		spriteSheet = inSpriteSheet; 
		spriteSheetID = inID;
	}
	void load(json::JSON loadNode);
};

#endif