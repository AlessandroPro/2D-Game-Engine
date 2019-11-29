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
	time_t speed = 1;
	time_t timeClipChanged = -1;
	sf::Texture spriteSheet;
	std::vector<sf::IntRect> frames;
	Sprite* sprite;
	int currentSpriteIndex;
	bool isPlaying = false;
	bool isLoopable = false;

protected:
	void initialize() override;
	void update(float deltaTime) override;
	void play() { isPlaying = true; }
	void stop() 
	{ 
		isPlaying = false; 
		timeClipChanged = -1;
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
	void setSprite(Sprite* inSprite) { sprite = inSprite; }
	void setSpriteSheet(sf::Texture inSpriteSheet) { spriteSheet = inSpriteSheet; }
	//void loadNode(json::JSON loadNode);
};

#endif