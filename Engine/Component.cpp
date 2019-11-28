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

//void Component::update(float deltaTime)
//{
//	if (!enabled)
//	{
//		return;
//	}
//}

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

void Component::onCollisionEnter(STRCODE)
{
}

void Component::onCollisionStay(STRCODE)
{
}

void Component::onCollisionExit(STRCODE)
{
}

void Component::onTriggerEnter(STRCODE)
{
}

void Component::onTriggerStay(STRCODE)
{
}

void Component::onTriggerExit(STRCODE)
{
}
