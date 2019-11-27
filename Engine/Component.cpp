#include "Core.h"
#include "Component.h"

IMPLEMENT_ABSTRACT_CLASS(Component)

Component::Component()
{

}

Component::~Component()
{
	
}

void Component::initialize()
{
	Object::initialize();
}

void Component::update(float deltaTime)
{
}

void Component::load(json::JSON& node)
{
	
}

void Component::setGameObject(GameObject* _gameObject)
{
	gameObject = _gameObject;
}

GameObject* Component::getGameObject()
{
	return gameObject;
}

void Component::onCollisionEnter(const ICollidable* const other)
{
}

void Component::onCollisionStay(const ICollidable* const other)
{
}

void Component::onCollisionExit(const ICollidable* const other)
{
}

void Component::onTriggerEnter(const ICollidable* const other)
{
}

void Component::onTriggerStay(const ICollidable* const other)
{
}

void Component::onTriggerEXit(const ICollidable* const other)
{
}
