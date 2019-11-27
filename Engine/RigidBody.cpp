#include "Core.h"
#include "ICollidable.h"
#include "RigidBody.h"
#include "CollisionSystem.h"

IMPLEMENT_DYNAMIC_CLASS(RigidBody)

RigidBody::RigidBody()
{
	//add this to collision system on construction
	CollisionSystem::instance().addRigidBody(this);
	body = nullptr;
	//enabled = true;
}

RigidBody::~RigidBody()
{
	//remove on destruction
	CollisionSystem::instance().removeRigidBody(this);
}

void RigidBody::addCollidable(ICollidable* collider)
{
	if (collider == nullptr)
	{
		return;
	}
	if (body != nullptr && !containsCollider(collider))
	{
		body->CreateFixture(&collider->fixtureDefinition);
		colliders.push_back(collider);
	}
}

void RigidBody::removeCollidable(ICollidable* collider)
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

void RigidBody::load(json::JSON& componentData)
{

}

