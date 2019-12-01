///-------------------------------------------------------------------------------------------------
// file: Component.h
//
// author: Abishek Tippireddy
//
// summary:	Component
///-------------------------------------------------------------------------------------------------
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#pragma once

#include "Object.h"


class GameObject;
struct Collision;
class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object)

	friend class GameObject;
	friend class CollisionSystem;

private:
	GameObject* gameObject = nullptr;

	
private:
	void setGameObject(GameObject* _gameObject);
	virtual void onCollisionEnter(const Collision* const collisionData);
	virtual void onCollisionStay(const Collision* const collisionData);
	virtual void onCollisionExit(const Collision* const collisionData);
	virtual void onTriggerEnter(const Collision* const collisionData);
	virtual void onTriggerStay(const Collision* const collisionData);
	virtual void onTriggerExit(const Collision* const collisionData);
protected:
	bool enabled = true;
protected:
	Component();
	virtual ~Component();
    virtual void initialize() override;
	virtual void update(float deltaTime)=0;
	virtual void load(json::JSON& node) override;

public:
	GameObject* getGameObject();
	virtual void setEnabled(bool _enabled) = 0;
	bool isEnabled();
};

#endif 