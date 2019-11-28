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

void CollisionSystem::checkCollision(RigidBody* rigidBody, ICollidable* collider)
{
	for (auto rbCollider : rigidBody->colliders)
	{
		CollisionSystem::Collision* collisionData = nullptr;
		if (rbCollider->collisionIDs.begin() != rbCollider->collisionIDs.end())
		{
			for (auto collisionID : rbCollider->collisionIDs)
			{
				if (std::count(collider->collisionIDs.begin(), collider->collisionIDs.end(), collisionID) == 1)
				{
					collisionData = activeCollisions[collisionID];
					break;
				}
			}
		}
		if (collisionData == nullptr)
		{
			collisionData = new CollisionSystem::Collision();
			collisionData->colliders[0] = rbCollider;
			collisionData->colliders[1] = collider;
			collisionData->collisionManifold = nullptr;
		}
		checkCollision(collisionData);
	}
}

void CollisionSystem::checkCollision(CollisionSystem::Collision* collisionData)
{
	bool newCollision = collisionData->collisionManifold != nullptr;
	b2Manifold* newManifold = new b2Manifold();
	if (collisionData->colliders[0]->shape->GetType() == b2Shape::Type::e_circle && 
		collisionData->colliders[1]->shape->GetType() == b2Shape::Type::e_circle)
	{
		b2CollideCircles(newManifold, 
			(b2CircleShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform, 
			(b2CircleShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform);
	}
	else if (collisionData->colliders[0]->shape->GetType() == b2Shape::Type::e_circle && 
		collisionData->colliders[1]->shape->GetType() == b2Shape::Type::e_polygon)
	{
		b2CollidePolygonAndCircle(newManifold,
			(b2PolygonShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform,
			(b2CircleShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform);
	}
	else if (collisionData->colliders[0]->shape->GetType() == b2Shape::Type::e_polygon && 
		collisionData->colliders[1]->shape->GetType() == b2Shape::Type::e_circle)
	{
		b2CollidePolygonAndCircle(newManifold,
			(b2PolygonShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform,
			(b2CircleShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform);

	}
	else if (collisionData->colliders[0]->shape->GetType() == b2Shape::Type::e_polygon && 
		collisionData->colliders[1]->shape->GetType() == b2Shape::Type::e_polygon)
	{
		b2CollidePolygons(newManifold,
			(b2PolygonShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform,
			(b2PolygonShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform);
	}
	collisionData->collisionManifold = newManifold;
	//this means that collision just happened
	if (collisionData->collisionManifold->pointCount > 0)
	{
		if (newCollision)
		{
			//create a strcode
			//add to activeCollisions
			//add to each collider's list
			//call on collision enter/ on trigger enter
		}
		else
		{
			//call on collision stay
		}
	}
	else
	{
		if (!newCollision)
		{
			//add to remove list for next update
			//call on collision exit/ on trigger exit
		}
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
				checkCollision(rigidBody, collider);
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
