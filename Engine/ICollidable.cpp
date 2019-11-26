#include "Core.h"
#include "ICollidable.h"

ICollidable::ICollidable()
{
	//add this to collision system on construction
	CollisionSystem::instance().addCollidable(this);

	trigger = false;
	shape = nullptr;
	manifold = nullptr;
}

ICollidable::~ICollidable()
{
	//remove on destruction
	CollisionSystem::instance().removeCollidable(this);
	
	delete shape;
	delete manifold;
}


