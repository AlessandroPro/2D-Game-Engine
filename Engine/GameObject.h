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

	// std::map<STRCODE, GameObject*> children;
	// GameObject* parent = nullptr;

public:
	std::string name;
	bool enabled = true;

protected:
	GameObject() = default;
	~GameObject();
	void initialize() override;
	void load(json::JSON& node) override;
	void update(float deltaTime);
	void deleteFromRemoveList();

public:
	void addComponent(Component* component);
	void removeComponent(STRCODE compID);
	std::map<STRCODE, Component*>& getAllComponents();
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

	//void detachChildren(bool toWorld);
	//void detachChild(GameObject* childObject, bool toWorld);
	//void removeChildren();
	//std::map<STRCODE, GameObject*>& getChildren();
	//GameObject* getParent();
	//void setParent(GameObject* parentObject);
};

#endif