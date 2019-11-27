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
class ICollidable;
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
	virtual void update(float deltaTime);
	virtual void load(json::JSON& node);
public:
    void setGameObject(GameObject* _gameObject);
	GameObject* getGameObject();
	virtual void onCollisionEnter(const ICollidable* const other);
	virtual void onCollisionStay(const ICollidable* const other);
	virtual void onCollisionExit(const ICollidable* const other);
	virtual void onTriggerEnter(const ICollidable* const other);
	virtual void onTriggerStay(const ICollidable* const other);
	virtual void onTriggerEXit(const ICollidable* const other);
};

#endif 