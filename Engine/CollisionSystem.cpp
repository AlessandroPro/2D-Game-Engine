#include "Core.h"
#include "ISystem.h"
#include "CollisionSystem.h"
#include "ICollidable.h"
#include "RigidBody.h"

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
