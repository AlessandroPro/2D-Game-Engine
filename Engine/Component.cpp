#include "Core.h"
#include "Component.h"

IMPLEMENT_ABSTRACT_CLASS(Component)

void Component::initialize()
{
    Object::initialize();
}

void Component::update(float deltaTime)
{
}
