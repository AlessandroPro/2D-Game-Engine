#include "Core.h"
#include "RigidBody.h"


RigidBody::RigidBody()
{
	//add this to collision system on construction
	CollisionSystem::instance().addRigidBody(this);
}

RigidBody::~RigidBody()
{
	//remove on destruction
	CollisionSystem::instance().removeRigidBody(this);
}
void RigidBody::initialize()
{
}

void RigidBody::update(float deltaTime)
{
}

