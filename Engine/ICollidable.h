#pragma once
#include "Box2D/Box2D.h"
#include "CollisionSystem.h"

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

