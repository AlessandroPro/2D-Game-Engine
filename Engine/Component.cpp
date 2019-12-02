#include "Core.h"
#include "Component.h"
#include "GameObject.h"

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

	if (node.hasKey("enabled"))
	{
		enabled = node["enabled"].ToBool();
	}
}

bool Component::isEnabled()
{
	return enabled;
}

void Component::setGameObject(GameObject* _gameObject)
{
	gameObject = _gameObject;
}

GameObject* Component::getGameObject()
{
	return gameObject;
}

void Component::setEnabled(bool _enabled)
{
	enabled = _enabled;
	if (enabled && getGameObject()->isEnabled() && !initialized)
	{
		initialize();
	}
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
