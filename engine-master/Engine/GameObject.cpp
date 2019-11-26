#include "Core.h"
#include "GameObject.h"
#include "Component.h"

IMPLEMENT_DYNAMIC_CLASS(GameObject)

GameObject::~GameObject()
{
	for (auto component : components)
	{
		delete component;
	}
}

void GameObject::initialize(json::JSON& gameObjectNode)
{
	_ASSERT_EXPR(gameObjectNode.hasKey("Name"), "gameObjectNode Node missing Name");
	name = gameObjectNode["Name"].ToString();

	if (gameObjectNode.hasKey("Components"))
	{
		json::JSON componentsNode = gameObjectNode["Components"];
		for (auto& componentNode : componentsNode.ArrayRange())
		{
			_ASSERT_EXPR(componentNode.hasKey("className"), "gameObjectNode Node missing className");
			std::string className = componentNode["className"].ToString();

            // How do we create by string?
			Component* component = new Component();
			component->initialize(componentNode);
			addComponent(component);
		}
	}
}

void GameObject::addComponent(Component* component)
{
	if (component != nullptr)
	{
		components.push_back(component);
	}
}

void GameObject::removeComponent(Component* component)
{
	components.remove(component);
}

void GameObject::update()
{
	for (auto component : components)
	{
		component->update();
	}
}