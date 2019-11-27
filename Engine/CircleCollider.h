///-------------------------------------------------------------------------------------------------
// file: CircleCollider.h
//
// editors: Rishi Barnwal , Dakshvir Rehill
//
// summary:	CircleCollider Component (A Collider with a radius and origin)
///-------------------------------------------------------------------------------------------------
#pragma once
#ifndef _CIRCLE_COLLIDER_H_
#define _CIRCLE_COLLIDER_H_
#include "ICollidable.h"
#include "Component.h"
class CircleCollider : public Component, public ICollidable
{
protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& componentData);

public:
	CircleCollider();
	~CircleCollider();
};

#endif