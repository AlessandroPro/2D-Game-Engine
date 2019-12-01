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
	std::string name = "";
	std::string currentAnimationName = "";
	std::map<std::string, Animation*> animations;
	std::vector<STRCODE> animationIDs;

protected:
	void initialize() override;
	void update(float deltaTime) override;
	void addAnimation(Animation* animation);
	void removeAnimation(Animation* animation);
	void load(json::JSON& loadNode) override;
	friend class Animation;
public:
	Animator();
	~Animator();
	void setCurrentAnimation(std::string animation) { currentAnimationName = animation; }
	void playCurrentAnimation() { animations[currentAnimationName]->play(); }
	void stopCurrentAnimation() { animations[currentAnimationName]->stop(); }
};

#endif