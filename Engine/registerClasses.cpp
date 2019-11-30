#include "Core.h"

#include "Object.h"
#include "GameObject.h"
#include "Component.h"
#include "Sprite.h"
#include "Transform.h"
#include "Camera.h"
#include "Animation.h"
#include "Animator.h"


void registerEngineClasses()
{
	REGISTER_ABSTRACT_CLASS(Object);
	REGISTER_ABSTRACT_CLASS(Component);
	REGISTER_DYNAMIC_CLASS(GameObject);
	REGISTER_DYNAMIC_CLASS(Sprite);
	REGISTER_DYNAMIC_CLASS(Transform);
	REGISTER_DYNAMIC_CLASS(Camera);
	REGISTER_DYNAMIC_CLASS(Animation);
	REGISTER_DYNAMIC_CLASS(Animator);
	REGISTER_ABSTRACT_CLASS(Asset);
	REGISTER_DYNAMIC_CLASS(PrefabAsset);
	REGISTER_DYNAMIC_CLASS(TextureAsset);
	REGISTER_DYNAMIC_CLASS(AudioAsset);
	REGISTER_DYNAMIC_CLASS(FontAsset);

	//Collision Classes
	REGISTER_ABSTRACT_CLASS(ICollidable);
	REGISTER_DYNAMIC_CLASS(CircleCollider);
	REGISTER_DYNAMIC_CLASS(PolygonCollider);
	REGISTER_DYNAMIC_CLASS(RigidBody);
}