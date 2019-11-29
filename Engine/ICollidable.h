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
class GameObject;
class ICollidable
{
	friend class CollisionSystem;
	friend class RigidBody;
private:
	DECLARE_ABSTRACT_BASE_CLASS(ICollidable)
protected:
	bool staticCollider;
	b2Transform b2transform;
	b2FixtureDef fixtureDefinition;
	b2Shape* shape;
	std::list<STRCODE> collisionIDs;
	bool trigger;
protected:
	ICollidable();
	virtual GameObject* getCurrentGameObject() = 0;
public:
	virtual ~ICollidable();
	virtual void setTrigger(bool isTrigger) = 0;
};

#endif