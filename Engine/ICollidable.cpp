#include "Core.h"
#include "ICollidable.h"

ICollidable::ICollidable()
{
	//add this to collision system on construction
	CollisionSystem::instance().addCollidable(this);
}

ICollidable::~ICollidable()
{
	//remove on destruction
	CollisionSystem::instance().removeCollidable(this);
}
