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
	std::map<STRCODE, GameObject*> children;
	GameObject* parent = nullptr;
	Transform* transform = nullptr;
	STRCODE levelID = 0;

public:
	std::string name;
	bool enabled = true;

protected:
	GameObject() = default;
	~GameObject();
	void initialize() override;
	void load(json::JSON& node) override;
	void update(float deltaTime);

public:
	void detachChildren(bool toWorld);
	void detachChild(Component* component, bool toWorld);
	void removeChildren();
	void addComponent(Component* component);
	void removeComponent(STRCODE compID);
	std::map<STRCODE, Component*>& getAllComponents();
	Component* getComponent(STRCODE compID);
	Component* getComponent(std::string& compType);
	std::list<Component*> getComponents(std::string& compType);
	std::map<STRCODE, GameObject*>& getChildren();
	GameObject* getParent();
	void setParent(GameObject* parentObject);
	Transform* getTransform();
	void createComponents(std::list<std::string>& compTypes);
	void createComponent(std::string& compType);

	template<class T>
	Component* createComponent()
	{
		T* component = new T();
		addComponent(component);
		component->initialize();
		return component;
	}
};

#endif