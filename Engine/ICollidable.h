///-------------------------------------------------------------------------------------------------
// file: ICollidable.h
//
// editors: Rishi Barnwal , Dakshvir Rehill
//
// summary:	ICollidable Interface (Every collider component needs to be an ICollidable)
///-------------------------------------------------------------------------------------------------
#pragma once
#ifndef _I_COLLIDABLE_H_
#define _I_COLLIDABLE_H_
#include "Component.h"
class ICollidable : public Component
{
	DECLARE_ABSTRACT_DERIVED_CLASS(ICollidable,Component)
	friend class CollisionSystem;
	friend class RigidBody;
protected:
	bool staticCollider; //colliders with no rigidBody
	b2Transform b2transform; //position of collider in the world
	b2FixtureDef fixtureDefinition; //internal definition so that the collider can be added to the rigidBody
	b2Shape* shape; //the shape of the collider
	std::list<STRCODE> collisionIDs; //current active collisions of this collider
	bool trigger;
protected:
	ICollidable();
public:
	virtual ~ICollidable();
	virtual void setTrigger(bool isTrigger) = 0;
};

#endif