#pragma once
#include "Box2D/Box2D.h"

class ICollidable
{
	friend class CollisionSystem;

private:
	b2Transform transform;

protected:
	b2Shape* shape;
	b2Manifold* manifold;
	b2DistanceOutput* distance;

protected:
	ICollidable() = default;

public:
	bool trigger;

public:
	virtual ~ICollidable() = default;
	inline const b2Shape* const getShape() { return shape; }
	inline const b2Manifold* const getManifold() { return manifold; }
	inline const b2DistanceOutput* const getDistanceOutput() { return distance; }

};

