#include "Core.h"
#include "ISystem.h"
#include "CollisionSystem.h"
#include "ICollidable.h"
#include "RigidBody.h"

CollisionSystem::~CollisionSystem()
{
	if (physicsWorld != nullptr)
	{
		delete physicsWorld;
	}
}

void CollisionSystem::initialize()
{
	physicsWorld = new b2World(GRAVITY);
}

void CollisionSystem::update(float deltaTime)
{
	for (auto rigidBody : rigidbodies)
	{
		for (auto collider : colliders)
		{
			if (!rigidBody->containsCollider(collider))
			{
				//check collision
				//set collision states
				//call all callbacks
			}
		}
	}
	physicsWorld->Step(PHYSICS_TIME_STEP, PHYSICS_VELOCITY_ITERATIONS, PHYSICS_POSITION_ITERATIONS);
}

//Returns the created b2Body if physicsWorld is not null else returns null
b2Body* CollisionSystem::CreateRigidBodyInWorld(b2BodyDef& bodyDefinition)
{
	return physicsWorld == nullptr ? nullptr : physicsWorld->CreateBody(&bodyDefinition);
}

//Removes the b2Body from physicsWorld
void CollisionSystem::RemoveRigidBodyFromWorld(b2Body* rigidBody)
{
	if (physicsWorld != nullptr)
	{
		physicsWorld->DestroyBody(rigidBody);
	}
}
