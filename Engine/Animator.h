///-------------------------------------------------------------------------------------------------
// file: Animator.h
//
// author: Justin Hole
// date: 11/28/2019
//
// summary:	Component that switches between (controls) the different animations of a character
///-------------------------------------------------------------------------------------------------
#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_
#pragma once

#include "Component.h"
#include "Animation.h"

class Animator: public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Animator, Component)

private:
	std::string currentAnimationName;
	std::map<std::string, Animation*> animations; //all animations that this animator can choose from to play

protected:
	void initialize() override;
	void update(float deltaTime) override;

	friend class RenderSystem;

public:
	Animator();
	~Animator();
	void setCurrentAnimation(std::string animation) { currentAnimationName = animation; }
	void addAnimation(Animation* animation);
	void removeAnimation(Animation* animation);
	//void loadNode(json::JSON loadNode);
	void playCurrentAnimation() { animations[currentAnimationName]->play(); }
	void stopCurrentAnimation() { animations[currentAnimationName]->stop(); }
};

#endif