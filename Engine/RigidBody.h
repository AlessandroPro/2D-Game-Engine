#pragma once
#include "Component.h"

class ICollidable;
class RigidBody : public Component
{
	friend class CollisionSystem;
	
protected:
	std::list<ICollidable*> colliders;

protected:
	void initialize();
	void update(float deltaTime);

public:
	RigidBody();
	virtual ~RigidBody() override;

	void addCollidable(ICollidable* collider);
	void removeCollidable(ICollidable* collider);

	void onCollisionEnter(const ICollidable* const other);
	void onCollisionStay(const ICollidable* const other);
	void onCollisionExit(const ICollidable* const other);
};

