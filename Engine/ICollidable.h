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
class ICollidable
{
	friend class CollisionSystem;

private:

protected:
	bool staticCollider;
	b2Transform b2transform;
	b2Shape* shape;
	b2Manifold* manifold;

protected:
	ICollidable();
	inline const b2Transform& const getB2Transform() { return b2transform; }

public:
	bool trigger;

public:
	virtual ~ICollidable();
	inline const b2Shape* const getShape() { return shape; }
	inline const b2Manifold* const getManifold() { return manifold; }

};

#endif