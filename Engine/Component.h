///-------------------------------------------------------------------------------------------------
// file: Component.h
//
// summary:	Component
///-------------------------------------------------------------------------------------------------
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#pragma once

#include "Object.h"

class CollisionSystem {
public:
	struct Collision;
};
class GameObject;

class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object)

	friend class GameObject;
	friend class CollisionSystem;

private:
	GameObject* gameObject = nullptr;
public:
	bool enabled=true;
	
private:
	void setGameObject(GameObject* _gameObject);
	virtual void onCollisionEnter(const CollisionSystem::Collision* const collisionData);
	virtual void onCollisionStay(const CollisionSystem::Collision* const collisionData);
	virtual void onCollisionExit(const CollisionSystem::Collision* const collisionData);
	virtual void onTriggerEnter(const CollisionSystem::Collision* const collisionData);
	virtual void onTriggerStay(const CollisionSystem::Collision* const collisionData);
	virtual void onTriggerExit(const CollisionSystem::Collision* const collisionData);

protected:
	Component();
	virtual ~Component();
    virtual void initialize() override;
	virtual void update(float deltaTime)=0;
	virtual void load(json::JSON& node) override;

public:
	GameObject* getGameObject();
};

#endif 