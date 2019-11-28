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

//Will return garbage when body is null
const b2Transform& RigidBody::getB2Transform()
{
	return body->GetTransform();
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
	if (body != nullptr)
	{
		//b2Vec2 position = b2Vec2(
		//	PIXEL_TO_METER(gameObject.getTransform().getPosition().x),
		//	PIXEL_TO_METER(gameObject.getTransform().getPosition().y);

		////convert degrees to radians
		//float rotation = DEG_TO_RAD(gameObject.getTransform().getRotation());

		////set transform
		//body->SetTransform(position, rotation);
	}
}

void RigidBody::load(json::JSON& componentData)
{
	//create b2BodyDef from componentData

	if (componentData.hasKey("BodyType")) {
		bodyDef.type = (b2BodyType)componentData["BodyType"].ToInt();
	}

	bodyDef.position.Set(
		PIXEL_TO_METER(gameObject.getTransform().getPosition().x),
		PIXEL_TO_METER(gameObject.getTransform().getPosition().y)
	);
}

