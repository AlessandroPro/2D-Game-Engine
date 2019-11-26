///-------------------------------------------------------------------------------------------------
// file: Component.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	Component
///-------------------------------------------------------------------------------------------------
#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#pragma once

#include "Object.h"

class GameObject;

class Component : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Component, Object)

private:
	int id = -1;

protected:
	GameObject* gameObject;

public:
	virtual void initialize() {}
	virtual void initialize(json::JSON& componentNode);

	virtual void update();

	int getComponentId();

	GameObject* getGameObject() { return gameObject; }
	void setGameObject(GameObject* value) { gameObject = value; }
};

#endif 