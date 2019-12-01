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
class CircleCollider :public ICollidable
{
private:
	DECLARE_DYNAMIC_DERIVED_CLASS(CircleCollider, ICollidable)
private:
	float32 colliderRadius; //variable to set the radius of the circle collider
protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& componentData) override;
public:
	CircleCollider();
	~CircleCollider();
	void setTrigger(bool isTrigger) override;
	void setEnabled(bool _enabled) override;
};

#endif