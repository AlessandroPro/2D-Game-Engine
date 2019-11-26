#include "Core.h"
#include "GameObject.h"
#include "Component.h"

IMPLEMENT_DYNAMIC_CLASS(GameObject)

GameObject::~GameObject()
{
}

void GameObject::initialize()
{
}

void GameObject::load(json::JSON& node)
{
}

void GameObject::update(float deltaTime)
{
}

void GameObject::detachChildren(bool toWorld)
{
}

void GameObject::detachChild(Component* component, bool toWorld)
{
}

void GameObject::removeChildren()
{
}

void GameObject::addComponent(Component* component)
{
}

void GameObject::removeComponent(STRCODE compID)
{
}

std::map<STRCODE, Component*>& GameObject::getAllComponents()
{
	return components;
}

Component* GameObject::getComponent(STRCODE compID)
{
	return nullptr;
}

Component* GameObject::getComponent(std::string& compType)
{
	return nullptr;
}

std::list<Component*> GameObject::getComponents(std::string& compType)
{
	return std::list<Component*>();
}

std::map<STRCODE, GameObject*>& GameObject::getChildren()
{
	return children;
}

GameObject* GameObject::getParent()
{
	return nullptr;
}

void GameObject::setParent(GameObject* parentObject)
{
}

Transform* GameObject::getTransform()
{
	return nullptr;
}

void GameObject::createComponents(std::list<std::string>& compTypes)
{
}

void GameObject::createComponent(std::string& compType)
{
}
