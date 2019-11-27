#include "Core.h"
#include "GameObject.h"
#include "Component.h"

IMPLEMENT_DYNAMIC_CLASS(GameObject)

GameObject::~GameObject()
{
	for (auto component : components)
	{
		if (component.second != nullptr)
		{
			delete component.second;
		}
	}
	components.clear();
	deleteFromRemoveList();
}

void GameObject::initialize()
{
	Object::initialize();

	if (getComponent(Transform::getClassHashCode()) == nullptr)
	{
		createComponent<Transform>();
	}

	for (auto component : components)
	{
		if (component.second != nullptr)
		{
			component.second->initialize();
		}
	}

}

void GameObject::load(json::JSON& node)
{
	if (node.hasKey("Components"))
	{
		json::JSON componentsNode = node["Components"];
		for (auto& componentNode : componentsNode.ArrayRange())
		{
			_ASSERT_EXPR(componentNode.hasKey("class"), "Missing class name");

			std::string compType = componentNode["class"].ToString();

			Component* component = static_cast<Component*>(CRtti::constructObject(compType.c_str()));
			addComponent(component);
			
			component->load(componentNode);
		}
	}

	Object::load(node);
}

void GameObject::update(float deltaTime)
{
	deleteFromRemoveList();

	if (!enabled)
	{
		return;
	}

	for (auto component : components)
	{
		if (component.second != nullptr)
		{
			component.second->update(deltaTime);
		}
	}
}

void GameObject::deleteFromRemoveList()
{
	//Created this as a function since it would be written multiple times otherwise
	for (auto component : componentsToRemove)
	{
		if (component != nullptr)
		{
			delete component;
		}
	}
	componentsToRemove.clear();
}

void GameObject::addComponent(Component* component)
{
	components.emplace(component->getID(), component);
}

void GameObject::removeComponent(STRCODE compID)
{
	if (components.find(compID) != components.end())
	{
		componentsToRemove.push_back(components[compID]);
	}
}

std::map<STRCODE, Component*>& GameObject::getAllComponents()
{
	return components;
}

Component* GameObject::getComponent(STRCODE compID)
{
	if (components.find(compID) != components.end())
	{
		return components[compID];
	}

	return nullptr;
}

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

