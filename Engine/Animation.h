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

#include "Component.h"

class Sprite;
class TextureAsset;
class Animation : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Animation, Component)

private:
	std::string name = "";
	float speed = 1.0f;
	double timeSinceLastFrame = 0;
	std::string textureGUID;
	std::vector<sf::IntRect> frames;
	STRCODE spriteSheetID = -1;
	STRCODE spriteID = -1;
	int currentSpriteIndex = -1;
	bool isPlaying = false;
	bool isLoopable = false;
	Sprite* sprite = nullptr;
	TextureAsset* asset = nullptr;
protected:
	void initialize() override;
	void update(float deltaTime) override;
	void play();
	void stop()
	{
		isPlaying = false;
		timeSinceLastFrame = -1;
	}
	void load(json::JSON& loadNode) override;

	friend class Animator;
public:
	Animation();
	~Animation();
	std::string& getName() { return name; }
	void setName(std::string inName) { name = inName; }
	void setSpeed(float inSpeed) { speed = inSpeed; }
	void setFrames(std::vector<sf::IntRect> inFrames) { frames = inFrames; }
	void setLoopingStatus(bool inLoopable) { isLoopable = inLoopable; }
};

#endif