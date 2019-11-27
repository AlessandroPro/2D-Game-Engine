#pragma once
#include "Component.h"
#include "Animation.h"

class Animator: public Component
{
private:
	std::string currentAnimationInPlay;
	std::list<Animation*> animations; //all animations that this animator can choose from to play

protected:
	void initialize() override;
	void update(float deltaTime) override;

	friend class RenderSystem;

public:
	Animator();
	~Animator();
};

