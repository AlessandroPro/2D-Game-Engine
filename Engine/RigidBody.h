///-------------------------------------------------------------------------------------------------
// file: RigidBody.h
//
// editors: Rishi Barnwal , Dakshvir Rehill
//
// summary:	RigidBody Component (Only gameObjects with this component will collide will all colliders)
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
#endif