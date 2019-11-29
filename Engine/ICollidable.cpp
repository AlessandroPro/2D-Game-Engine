#include "Core.h"
#include "CollisionSystem.h"
#include "ICollidable.h"

IMPLEMENT_ABSTRACT_CLASS(ICollidable)

ICollidable::ICollidable()
{
	//add this to collision system on construction
	CollisionSystem::instance().addCollidable(this);
	staticCollider = false;
	trigger = false;
	shape = nullptr;
}

ICollidable::~ICollidable()
{
	//remove on destruction
	CollisionSystem::instance().removeCollidable(this);
	
	if (staticCollider)
	{
		delete shape;
	}
}


