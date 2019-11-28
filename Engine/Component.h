///-------------------------------------------------------------------------------------------------
// file: Component.h
//
// 
// 
//
// summary:	Component
///-------------------------------------------------------------------------------------------------
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#pragma once

#include "Object.h"
#include <string>
class CollisionSystem {
public:
	struct Collision;
};
class GameObject;

class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object)

	friend class GameObject;

private:
	GameObject* gameObject = nullptr;
public:
	bool enabled=true;
	
protected:
	Component();
	virtual ~Component();
    virtual void initialize() override;
	virtual void update(float deltaTime)=0;
	virtual void load(json::JSON& node) override;
public:
    void setGameObject(GameObject* _gameObject);
	GameObject* getGameObject();
	virtual void onCollisionEnter(const CollisionSystem::Collision* const other);
	virtual void onCollisionStay(const CollisionSystem::Collision* const other);
	virtual void onCollisionExit(const CollisionSystem::Collision* const other);
	virtual void onTriggerEnter(const CollisionSystem::Collision* const other);
	virtual void onTriggerStay(const CollisionSystem::Collision* const other);
	virtual void onTriggerExit(const CollisionSystem::Collision* const other);
};

#endif 