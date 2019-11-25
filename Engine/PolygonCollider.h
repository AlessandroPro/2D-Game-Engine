#pragma once
#include "ICollidable.h"
#include "Component.h"

class PolygonCollider : public ICollidable, public Component
{
protected:
	void initialize() override;
	void update(float deltaTime) override;

public:
	bool enabled;
	GameObject* gameObject;

public:
	PolygonCollider();
	~PolygonCollider();
};

