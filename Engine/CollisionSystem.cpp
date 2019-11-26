#include "Core.h"
#include "CollisionSystem.h"

CollisionSystem::~CollisionSystem()
{
	for (ICollidable* ic : colliders) {
		delete ic;
	}

	for (RigidBody* rb : rigidbodies) {
		delete rb;
	}
}

void CollisionSystem::initialize()
{
}

void CollisionSystem::update(float deltaTime)
{
}
