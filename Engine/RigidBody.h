#pragma once
#include "ICollidable.h"
#include "GameObject.h"
#include "Component.h"

class RigidBody : public Component
{
	friend class CollisionSystem;
	
protected:
	std::list<ICollidable*> colliders;

protected:
	void initialize();
	void update(float deltaTime);

public:
	bool enabled;
	GameObject* gameObject;

public:
	RigidBody();
	virtual ~RigidBody() override;

	void onCollisionEnter(const ICollidable* const other);
	void onCollisionStay(const ICollidable* const other);
	void onCollisionExit(const ICollidable* const other);
};

