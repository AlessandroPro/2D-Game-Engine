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

		}
	}
	physicsWorld->Step(PHYSICS_TIME_STEP, PHYSICS_VELOCITY_ITERATIONS, PHYSICS_POSITION_ITERATIONS);
}
