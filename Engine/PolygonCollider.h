#pragma once
#ifndef _POLYGON_COLLIDER_H_
#define _POLYGON_COLLIDER_H_
#include "ICollidable.h"
#include "Component.h"
class PolygonCollider : public ICollidable, public Component
{

protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& componentData);

public:
	PolygonCollider();
	~PolygonCollider();
};
#endif