#include "Core.h"
#include "CollisionSystem.h"
#include "ICollidable.h"
#include "RigidBody.h"
#include "GameObject.h"
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
		Collision* collisionData = nullptr;
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
			collisionData = new Collision();
			collisionData->colliders[0] = rbCollider;
			collisionData->colliders[1] = collider;
			collisionData->collisionManifold = nullptr;
		}
		checkCollision(collisionData);
	}
}

void CollisionSystem::checkCollision(Collision* collisionData)
{
	bool newCollision = collisionData->collisionManifold == nullptr;

	b2Manifold* newManifold = new b2Manifold();
	bool isShapeOneCircle = collisionData->colliders[0]->shape->GetType() == b2Shape::Type::e_circle;
	bool isShapeTwoCircle = collisionData->colliders[1]->shape->GetType() == b2Shape::Type::e_circle;
	bool isShapeOnePolygon = collisionData->colliders[0]->shape->GetType() == b2Shape::Type::e_polygon;
	bool isShapeTwoPolygon = collisionData->colliders[1]->shape->GetType() == b2Shape::Type::e_polygon;
	if (isShapeOneCircle && isShapeTwoCircle)
	{
		b2CollideCircles(newManifold, 
			(b2CircleShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform, 
			(b2CircleShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform);
	}
	else if (isShapeOneCircle && isShapeTwoPolygon)
	{
		b2CollidePolygonAndCircle(newManifold,
			(b2PolygonShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform,
			(b2CircleShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform);
	}
	else if (isShapeOnePolygon && isShapeTwoCircle)
	{
		b2CollidePolygonAndCircle(newManifold,
			(b2PolygonShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform,
			(b2CircleShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform);

	}
	else if (isShapeOnePolygon && isShapeTwoPolygon)
	{
		b2CollidePolygons(newManifold,
			(b2PolygonShape*)(collisionData->colliders[0]->shape), collisionData->colliders[0]->b2transform,
			(b2PolygonShape*)(collisionData->colliders[1]->shape), collisionData->colliders[1]->b2transform);
	}
	//this means that collision just happened
	if (newManifold->pointCount > 0)
	{
		if (newCollision)
		{
			UUID newUUID;
			CreateUUID(&newUUID);
			STRCODE uidStrCode = GUIDToSTRCODE(newUUID);
			collisionData->collisionId = uidStrCode;
			activeCollisions.emplace(uidStrCode, collisionData);
			collisionData->colliders[0]->collisionIDs.push_back(uidStrCode);
			collisionData->colliders[1]->collisionIDs.push_back(uidStrCode);
			collisionData->collisionManifold = new b2WorldManifold();
			collisionData->collisionManifold->Initialize(newManifold,
				collisionData->colliders[0]->b2transform, collisionData->colliders[0]->shape->m_radius,
				collisionData->colliders[1]->b2transform, collisionData->colliders[1]->shape->m_radius);
			collisionData->localCollisionManifold = newManifold;
			if (collisionData->colliders[0]->trigger || collisionData->colliders[1]->trigger)
			{
				for (auto component : collisionData->colliders[0]->getGameObject()->getAllComponents())
				{
					component.second->onTriggerEnter(collisionData);
				}
				for (auto component : collisionData->colliders[1]->getGameObject()->getAllComponents())
				{
					component.second->onTriggerEnter(collisionData);
				}
			}
			else
			{
				for (auto component : collisionData->colliders[0]->getGameObject()->getAllComponents())
				{
					component.second->onCollisionEnter(collisionData);
				}
				for (auto component : collisionData->colliders[1]->getGameObject()->getAllComponents())
				{
					component.second->onCollisionEnter(collisionData);
				}
			}
		}
		else
		{
			if (collisionData->colliders[0]->trigger || collisionData->colliders[1]->trigger)
			{
				for (auto component : collisionData->colliders[0]->getGameObject()->getAllComponents())
				{
					component.second->onTriggerStay(collisionData);
				}
				for (auto component : collisionData->colliders[1]->getGameObject()->getAllComponents())
				{
					component.second->onTriggerStay(collisionData);
				}
			}
			else
			{
				for (auto component : collisionData->colliders[0]->getGameObject()->getAllComponents())
				{
					component.second->onCollisionStay(collisionData);
				}
				for (auto component : collisionData->colliders[1]->getGameObject()->getAllComponents())
				{
					component.second->onCollisionStay(collisionData);
				}
			}
		}
	}
	else
	{
		if (!newCollision)
		{
			if (collisionData->colliders[0]->trigger || collisionData->colliders[1]->trigger)
			{
				for (auto component : collisionData->colliders[0]->getGameObject()->getAllComponents())
				{
					component.second->onTriggerExit(collisionData);
				}
				for (auto component : collisionData->colliders[1]->getGameObject()->getAllComponents())
				{
					component.second->onTriggerExit(collisionData);
				}
			}
			else
			{
				for (auto component : collisionData->colliders[0]->getGameObject()->getAllComponents())
				{
					component.second->onCollisionExit(collisionData);
				}
				for (auto component : collisionData->colliders[1]->getGameObject()->getAllComponents())
				{
					component.second->onCollisionExit(collisionData);
				}
			}
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
b2Body* CollisionSystem::createRigidBodyInWorld(b2BodyDef& bodyDefinition)
{
	return physicsWorld == nullptr ? nullptr : physicsWorld->CreateBody(&bodyDefinition);
}

//Removes the b2Body from physicsWorld
void CollisionSystem::removeRigidBodyFromWorld(b2Body* rigidBody)
{
	if (physicsWorld != nullptr)
	{
		physicsWorld->DestroyBody(rigidBody);
	}
}
