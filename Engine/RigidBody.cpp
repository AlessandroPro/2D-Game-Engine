#include "Core.h"
#include "RigidBody.h"


RigidBody::RigidBody()
{
	//add this to collision system on construction
	CollisionSystem::instance().addRigidBody(this);

	enabled = true;
}

RigidBody::~RigidBody()
{
	//remove on destruction
	CollisionSystem::instance().removeRigidBody(this);

	for (ICollidable* ic : colliders) {
		delete ic;
	}
}
void RigidBody::addCollidable(ICollidable* ic)
{
}
void RigidBody::removeCollidable(ICollidable* ic)
{
}
void RigidBody::onCollisionEnter(const ICollidable* const other)
{
}
void RigidBody::onCollisionStay(const ICollidable* const other)
{
}
void RigidBody::onCollisionExit(const ICollidable* const other)
{
}
void RigidBody::initialize()
{
}

void RigidBody::update(float deltaTime)
{
}

