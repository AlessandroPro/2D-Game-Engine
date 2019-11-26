#pragma once
#include "ICollidable.h"
#include "Component.h"

class CircleCollider : public Component, public ICollidable
{
protected:
	void initialize() override;
	void update(float deltaTime) override;

public:
	CircleCollider();
	~CircleCollider();
};

