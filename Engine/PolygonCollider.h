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
class PolygonCollider : public ICollidable
{
private:
	DECLARE_DYNAMIC_DERIVED_CLASS(PolygonCollider,ICollidable)
	//DECLARE_DYNAMIC_DERIVED_CLASS(PolygonCollider,ICollidable)
private:
	b2Vec2 vertices[b2_maxPolygonVertices];
	int vertCount;
protected:
	void initialize() override;
	void update(float deltaTime) override;
	void load(json::JSON& componentData) override;

public:
	PolygonCollider();
	~PolygonCollider();
	void setTrigger(bool isTrigger) override;
};
#endif