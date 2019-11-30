#include "Core.h"

#include "Object.h"
#include "GameObject.h"
#include "Component.h"
#include "Sprite.h"
#include "Transform.h"

#include "ICollidable.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"
#include "RigidBody.h"

void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Sprite);
	REGISTER_DYNAMIC_CLASS(Transform);



	//Collision Classes
	REGISTER_ABSTRACT_CLASS(ICollidable);
	REGISTER_DYNAMIC_CLASS(CircleCollider);
	REGISTER_DYNAMIC_CLASS(PolygonCollider);
	REGISTER_DYNAMIC_CLASS(RigidBody);
}