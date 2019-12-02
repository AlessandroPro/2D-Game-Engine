#include "Core.h"
#include "GameObject.h"
#include "Component.h"

IMPLEMENT_DYNAMIC_CLASS(GameObject)

GameObject::GameObject()
{
	// Add the Transform component
	transform = new Transform();
	components.emplace(transform->getID(), transform);
	transform->setGameObject(this);

	name = "Game Object";
}

GameObject::~GameObject()
{
	for (auto& component : components)
	{
		if (component.second != nullptr)
		{
			delete component.second;
			component.second = nullptr;
		}
	}
	components.clear();
	deleteFromRemoveList();
}

void GameObject::initialize()
{
	if (!isEnabled())
	{
		return;
	}
	Object::initialize();

	for (auto component : components)
	{
		if (component.second != nullptr)
		{
			if (!component.second->initialized)
			{
				component.second->initialize();
			}
		}
	}
}

void GameObject::load(json::JSON& node)
{
	Object::load(node);

	if (node.hasKey("destroyOnUnload"))
	{
		destroyOnUnload = node["destroyOnUnload"].ToBool();
	}

	if (node.hasKey("enabled"))
	{
		enabled = node["enabled"].ToBool();
	}

	if (node.hasKey("name"))
	{
		name = node["name"].ToString();
	}

	if (node.hasKey("Components"))
	{
		json::JSON componentsNode = node["Components"];
		for (auto& componentNode : componentsNode.ArrayRange())
		{
			_ASSERT_EXPR(componentNode.hasKey("class"), "Component node mising class name.");

			std::string compType = componentNode["class"].ToString();

			Component* component;

			// Create and add the loaded component if it isn't a Transform.
			// If it is a Transform, just load its data, since the component already exists by default.
			if (getHashCode(compType.c_str()) != Transform::getClassHashCode())
			{
				component = static_cast<Component*>(CRtti::constructObject(compType.c_str()));
				addComponent(component);
			}
			else
			{
				component = getComponent(transform->getID());
			}
			component->load(componentNode);
		}
	}
}

void GameObject::update(float deltaTime)
{
	deleteFromRemoveList();

	if (!enabled)
	{
		return;
	}

	for (auto& component : components)
	{
		if (component.second != nullptr)
		{
			component.second->update(deltaTime);
		}
	}
}

void GameObject::deleteFromRemoveList()
{
	for (auto& component : componentsToRemove)
	{
		if (component != nullptr)
		{
			components.erase(component->getID());
			delete component;
		}
	}
	componentsToRemove.clear();
}

void GameObject::addComponent(Component* component)
{
	// Add the component if it is not a Transform, since there is already a Transform
	if (component->getDerivedClassHashCode() != Transform::getClassHashCode())
	{
		components.emplace(component->getID(), component);
		component->setGameObject(this);
	}
}

void GameObject::removeComponent(STRCODE compID)
{
	// Prevents removal of the Transform component
	if (transform->getID() != compID)
	{
		Component* component = getComponent(compID);

		if (component != nullptr)
		{
			componentsToRemove.push_back(component);
		}
	}
}

const std::map<STRCODE, Component*>& GameObject::getAllComponents()
{
	return components;
}

Component* GameObject::getComponent(STRCODE compID)
{
	auto iter = components.find(compID);

	if (iter != components.end())
	{
		return iter->second;
	}

	return nullptr;
}

// Retuns the first component found that matches the given compType
Component* GameObject::getComponent(const std::string& compType)
{
	STRCODE compTypeID = getHashCode(compType.c_str());

	for (auto component : components)
	{
		if (component.second != nullptr)
		{
			if (component.second->getDerivedClassHashCode() == compTypeID)
			{
				return component.second;
			}
		}
	}

	return nullptr;
}

// Retuns all components found in this game object that match the given compType
std::list<Component*> GameObject::getComponents(const std::string& compType)
{
	STRCODE compTypeID = getHashCode(compType.c_str());

	std::list<Component*> componentsOfType;

	for (auto component : components)
	{
		if (component.second != nullptr)
		{
			if (component.second->getDerivedClassHashCode() == compTypeID)
			{
				componentsOfType.push_back(component.second);
			}
		}
	}

	return componentsOfType;
}

Transform* GameObject::getTransform()
{
	return transform;
}

void GameObject::createComponents(std::list<std::string>& compTypes)
{
	for (auto compType : compTypes)
	{
		createComponent(compType);
	}
}

Component* GameObject::createComponent(const std::string& compType)
{
	Component* component = static_cast<Component*>(CRtti::constructObject(compType.c_str()));
	addComponent(component);
	component->initialize();
	return component;
}

void GameObject::setEnabled(bool _enabled)
{
	enabled = _enabled;
	if (enabled && !initialized)
	{
		initialize();
	}
}

bool GameObject::isEnabled()
{
	return enabled;
}

