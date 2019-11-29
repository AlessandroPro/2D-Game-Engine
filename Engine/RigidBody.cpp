#include "Core.h"
#include "CollisionSystem.h"
#include "RigidBody.h"
#include "GameObject.h"
#include "ICollidable.h"

IMPLEMENT_DYNAMIC_CLASS(RigidBody)

RigidBody::RigidBody()
{
	//add this to collision system on construction
	CollisionSystem::instance().addRigidBody(this);
	body = nullptr;
	lockedDirections[Transform::Direction::Up];
	lockedDirections[Transform::Direction::Down];
	lockedDirections[Transform::Direction::Left];
	lockedDirections[Transform::Direction::Right];
}

RigidBody::~RigidBody()
{
	//remove on destruction
	CollisionSystem::instance().removeRigidBodyFromWorld(body);
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
			collider->b2transform = body->GetTransform();
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

void RigidBody::onCollisionEnter(const Collision* const collisionData)
{
	int otherColliderIx = 1;
	if (collisionData->colliders[otherColliderIx]->getGameObject() == getGameObject())
	{
		otherColliderIx = 0;
	}
	sf::Vector2f collisionDirection(collisionData->colliders[otherColliderIx]->getGameObject()->getTransform()->getPosition() -
							getGameObject()->getTransform()->getPosition());
	
	if (collisionDirection.x > 0)
	{
		addCollisionToDirectionOnEnter(Transform::Direction::Right, collisionData->collisionId);
	}
	else if (collisionDirection.x < 0)
	{
		addCollisionToDirectionOnEnter(Transform::Direction::Left, collisionData->collisionId);
	}

	if (collisionDirection.y > 0)
	{
		addCollisionToDirectionOnEnter(Transform::Direction::Up, collisionData->collisionId);
	}
	else if (collisionDirection.y < 0)
	{
		addCollisionToDirectionOnEnter(Transform::Direction::Down, collisionData->collisionId);
	}

}

void RigidBody::onCollisionStay(const Collision* const collisionData)
{
	int otherColliderIx = 1;
	if (collisionData->colliders[otherColliderIx]->getGameObject() == getGameObject())
	{
		otherColliderIx = 0;
	}
	sf::Vector2f collisionDirection(collisionData->colliders[otherColliderIx]->getGameObject()->getTransform()->getPosition() -
		getGameObject()->getTransform()->getPosition());

	if (collisionDirection.x > 0)
	{
		addCollisionToDirectionOnStay(Transform::Direction::Right, collisionData->collisionId);
	}
	else if (collisionDirection.x < 0)
	{
		addCollisionToDirectionOnStay(Transform::Direction::Left, collisionData->collisionId);
	}

	if (collisionDirection.y > 0)
	{
		addCollisionToDirectionOnStay(Transform::Direction::Up, collisionData->collisionId);
	}
	else if (collisionDirection.y < 0)
	{
		addCollisionToDirectionOnStay(Transform::Direction::Down, collisionData->collisionId);
	}
}

void RigidBody::onCollisionExit(const Collision* const collisionData)
{
	int otherColliderIx = 1;
	if (collisionData->colliders[otherColliderIx]->getGameObject() == getGameObject())
	{
		otherColliderIx = 0;
	}
	sf::Vector2f collisionDirection(collisionData->colliders[otherColliderIx]->getGameObject()->getTransform()->getPosition() -
		getGameObject()->getTransform()->getPosition());

	if (collisionDirection.x > 0)
	{
		removeCollisionFromDirectionOnExit(Transform::Direction::Right, collisionData->collisionId);
	}
	else if (collisionDirection.x < 0)
	{
		removeCollisionFromDirectionOnExit(Transform::Direction::Left, collisionData->collisionId);
	}

	if (collisionDirection.y > 0)
	{
		removeCollisionFromDirectionOnExit(Transform::Direction::Up, collisionData->collisionId);
	}
	else if (collisionDirection.y < 0)
	{
		removeCollisionFromDirectionOnExit(Transform::Direction::Down, collisionData->collisionId);
	}

}


void RigidBody::addCollisionToDirectionOnEnter(Transform::Direction direction, STRCODE collisionID)
{
	lockedDirections[Transform::Direction::Right].push_back(collisionID);
	getGameObject()->getTransform()->setDirectionLock(direction, true);
}

void RigidBody::addCollisionToDirectionOnStay(Transform::Direction direction, STRCODE collisionID)
{
	if (std::count(lockedDirections[direction].begin(), lockedDirections[direction].end(), collisionID) == 0)
	{
		lockedDirections[direction].push_back(collisionID);
	}
	if (lockedDirections[direction].size() > 0)
	{
		getGameObject()->getTransform()->setDirectionLock(direction, true);
	}
}

void RigidBody::removeCollisionFromDirectionOnExit(Transform::Direction direction, STRCODE collisionID)
{
	if (std::count(lockedDirections[direction].begin(), lockedDirections[direction].end(), collisionID) != 0)
	{
		lockedDirections[direction].remove(collisionID);
	}

	if (lockedDirections[direction].size() <= 0)
	{
		getGameObject()->getTransform()->setDirectionLock(direction, false);
	}

}

void RigidBody::initialize()
{
	//create body in world
	body = CollisionSystem::instance().createRigidBodyInWorld(bodyDef);
	for (auto collider : colliders)
	{
		body->CreateFixture(&collider->fixtureDefinition);
		collider->b2transform = body->GetTransform();
	}
}

void RigidBody::update(float deltaTime)
{
	if (body != nullptr)
	{
		b2Vec2 position = b2Vec2(
			PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().x),
			PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().y));

		//convert degrees to radians
		float rotation = DEG_TO_RAD(getGameObject()->getTransform()->getRotation());

		//set transform
		body->SetTransform(position, rotation);
		for (auto collider : colliders)
		{
			collider->b2transform = body->GetTransform();
		}
	}
}

void RigidBody::load(json::JSON& componentData)
{
	//create b2BodyDef from componentData

	if (componentData.hasKey("BodyType")) {
		bodyDef.type = (b2BodyType)(componentData["BodyType"].ToInt());
	}

	bodyDef.position.Set(
		PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().x),
		PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().y));
}

