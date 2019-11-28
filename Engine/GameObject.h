///-------------------------------------------------------------------------------------------------
// file: GameObject.h
//
// summary:	The Game Object
///-------------------------------------------------------------------------------------------------
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#pragma once

#include "Object.h"
#include "Transform.h"

class Component;

class GameObject final : public Object
{    
    DECLARE_DYNAMIC_DERIVED_CLASS(GameObject, Object)

	friend class GameObjectManager;

private:
	std::map<STRCODE, Component*> components;
	std::list<Component*> componentsToRemove;
	Transform* transform = nullptr;
	STRCODE levelID = -1;

public:
	std::string name;
	bool enabled = true;
	bool destroyOnUnload = true;

protected:
	GameObject();
	~GameObject();
	void initialize() override;
	void load(json::JSON& node) override;
	void update(float deltaTime);
	void deleteFromRemoveList();

public:
	void addComponent(Component* component);
	void removeComponent(STRCODE compID);
	const std::map<STRCODE, Component*>& getAllComponents();
	Component* getComponent(STRCODE compID);
	Component* getComponent(const std::string& compType);
	std::list<Component*> getComponents(const std::string& compType);
	Transform* getTransform();
	void createComponents(std::list<std::string>& compTypes);
	Component* createComponent(const std::string& compType);

	template<class T>
	Component* createComponent()
	{
		Component* component = new T();
		addComponent(component);
		component->initialize();
		return component;
	}
};

#endif