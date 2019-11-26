#include "Core.h"
#include "Component.h"

IMPLEMENT_ABSTRACT_CLASS(Component)

void Component::initialize(json::JSON& componentNode)
{
	_ASSERT_EXPR(componentNode.hasKey("id"), "componentNode Node missing id");
	id = componentNode["id"].ToInt();
}

void Component::update()
{
}

int Component::getComponentId()
{
	return id;
}
