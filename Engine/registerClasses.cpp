#include "Core.h"

#include "Object.h"
#include "GameObject.h"
#include "Component.h"
#include "Sprite.h"

void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Sprite);
}