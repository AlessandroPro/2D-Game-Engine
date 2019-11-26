///-------------------------------------------------------------------------------------------------
// file: GameObject.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Transform
///-------------------------------------------------------------------------------------------------
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#pragma once

#include "Object.h"

class Component;

class GameObject : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(GameObject, Object)

private:
	std::list<Component*> components;
	std::string name = "";

	sf::Vector2f position;

public:
    GameObject() = default;
    virtual ~GameObject();

public:

	void initialize(json::JSON& document);
	void addComponent(Component* component);
	void removeComponent(Component* component);
	void update();

	const sf::Vector2f& getPosition() { return position; }
	void setPosition(const sf::Vector2f& value) { position = value; }

    friend class GameObjectManager;
};

#endif