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
	bool staticCollider;
	b2Transform b2transform;
	b2FixtureDef fixtureDefinition;
	b2Shape* shape;
	std::list<STRCODE> collisionIDs;
	bool trigger;
protected:
	ICollidable();
public:
	virtual ~ICollidable();
	virtual void setTrigger(bool isTrigger) = 0;
};

#endif