///-------------------------------------------------------------------------------------------------
// file: RigidBody.h
//
// editors: Rishi Barnwal , Dakshvir Rehill
//
// summary:	RigidBody Component (Only gameObjects with this component will collide with all colliders)
///-------------------------------------------------------------------------------------------------
#pragma once
#ifndef _RIGID_BODY_H_
#define _RIGID_BODY_H_
#include "Component.h"

class ICollidable;
class RigidBody : public Component
{
	friend class CollisionSystem;
private:
	DECLARE_DYNAMIC_DERIVED_CLASS(RigidBody,Component)
protected:
	std::list<ICollidable*> colliders;
	b2Body* body;
	b2BodyDef bodyDef;
protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& componentData) override;
	//function to check if collidable is already in rigidbody
	inline bool containsCollider(ICollidable* collider) { return std::count(colliders.begin(), colliders.end(),collider) == 1; }
public:
	RigidBody();
	virtual ~RigidBody() override;

	void addCollidable(ICollidable* collider);
	void removeCollidable(ICollidable* collider);

	void onCollisionEnter(const Collision* const collisionData) override;
	void onCollisionStay(const Collision* const collisionData) override;
	void onCollisionExit(const Collision* const collisionData) override;
};
#endif