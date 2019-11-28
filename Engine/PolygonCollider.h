///-------------------------------------------------------------------------------------------------
// file: PolygonCollider.h
//
// editors: Rishi Barnwal , Dakshvir Rehill
//
// summary:	PolygonCollider Component (A Collider with maximum 8 vertices)
///-------------------------------------------------------------------------------------------------
#pragma once
#ifndef _POLYGON_COLLIDER_H_
#define _POLYGON_COLLIDER_H_
#include "ICollidable.h"
#include "Component.h"
class PolygonCollider : public ICollidable, public Component
{
private:
	DECLARE_DYNAMIC_DERIVED_CLASS(PolygonCollider,Component)
	//DECLARE_DYNAMIC_DERIVED_CLASS(PolygonCollider,ICollidable)
protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& componentData);

public:
	PolygonCollider();
	~PolygonCollider();
	void setTrigger(bool b) override;
};
#endif