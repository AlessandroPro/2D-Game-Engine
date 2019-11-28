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
	if (!containsCollider(collider))
	{
		if (body != nullptr)
		{
			body->CreateFixture(&collider->fixtureDefinition);
		}
		colliders.push_back(collider);
	}
}

void RigidBody::removeCollidable(ICollidable* collider)
{
	if (collider == nullptr)
	{
		return;
	}
	if (body != nullptr && containsCollider(collider))
	{
		for (b2Fixture* currentFixture = body->GetFixtureList(); currentFixture != nullptr; currentFixture = currentFixture->GetNext())
		{
			if (currentFixture->GetShape() == collider->shape)
			{
				b2Fixture* fixtureToDestroy = currentFixture;
				currentFixture = currentFixture->GetNext();
				body->DestroyFixture(fixtureToDestroy);
				break;
			}
		}
		colliders.remove(collider);
	}
}

const b2Transform& RigidBody::getB2Transform()
{
	return body == nullptr ? b2Transform() : body->GetTransform();
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
	//create body in world
	body = CollisionSystem::instance().CreateRigidBodyInWorld(bodyDef);
	for (auto collider : colliders)
	{
		body->CreateFixture(&collider->fixtureDefinition);
	}
}

void RigidBody::update(float deltaTime)
{

}

void RigidBody::load(json::JSON& componentData)
{

}

