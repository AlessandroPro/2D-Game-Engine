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

void Component::load(json::JSON& node)
{
	Object::load(node);
}

void Component::setGameObject(GameObject* _gameObject)
{
	gameObject = _gameObject;
}

GameObject* Component::getGameObject()
{
	return gameObject;
}

void Component::onCollisionEnter(const Collision* const collisionData)
{
}

void Component::onCollisionStay(const Collision* const collisionData)
{
}

void Component::onCollisionExit(const Collision* const collisionData)
{
}

void Component::onTriggerEnter(const Collision* const collisionData)
{
}

void Component::onTriggerStay(const Collision* const collisionData)
{
}

void Component::onTriggerExit(const Collision* const collisionData)
{
}
