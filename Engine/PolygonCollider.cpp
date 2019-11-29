#include "Core.h"
#include "GameObject.h"
#include "RigidBody.h"
#include "PolygonCollider.h"

IMPLEMENT_DYNAMIC_CLASS(PolygonCollider)

PolygonCollider::PolygonCollider()
{
	vertCount = 0;
}

PolygonCollider::~PolygonCollider()
{

}

void PolygonCollider::setTrigger(bool isTrigger)
{
	trigger = isTrigger;
	Component* rigidBody = getGameObject()->getComponent("RigidBody");
	if (!staticCollider)
	{
		if (trigger)
		{
			if (rigidBody != nullptr)
			{
				dynamic_cast<RigidBody*>(rigidBody)->removeCollidable(this);
				b2transform.Set(b2Vec2(
					PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().x),
					PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().y)),
					DEG_TO_RAD(getGameObject()->getTransform()->getRotation()));
			}
			staticCollider = true;
		}
	}
	else
	{
		if (!trigger)
		{
			if (rigidBody != nullptr)
			{
				dynamic_cast<RigidBody*>(rigidBody)->addCollidable(this);
				staticCollider = false;
			}
		}
	}
}

GameObject* PolygonCollider::getCurrentGameObject()
{
	return getGameObject();
}

void PolygonCollider::initialize()
{
	Component::initialize();

	//get gameobject of component
	//if current gameobject has a rigidbody component
	//add this to that rigidbody
	b2PolygonShape* polygonShape = new b2PolygonShape();
	if (vertCount < 3)
	{
		polygonShape->SetAsBox(0.5, 0.5);
	}
	else
	{
		polygonShape->Set(vertices,vertCount);
	}

	shape = polygonShape;
	fixtureDefinition.shape = shape;

	if (!trigger)
	{
		Component* rigidBody = getGameObject()->getComponent("RigidBody");
		if (rigidBody != nullptr)
		{
			dynamic_cast<RigidBody*>(rigidBody)->addCollidable(this);
		}
		else
		{
			staticCollider = true;
		}
	}
	else
	{
		staticCollider = true;
	}

}

void PolygonCollider::update(float deltaTime)
{
	//move b2transform if and only if staticCollider is true

	//use gameobjects getTransform function and use transform.getposition, and transform.getrotation
	//convert that sf::vector2f and convert it into b2Vec2, and convert rotation from degs to rads
	//use b2transform.set and pass in the converted b2vec2, and the radians

	if (staticCollider)
	{
		//get transform and rotation from gameobject

		//convert transform to b2Transform
		b2Vec2 position = b2Vec2(
			PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().x),
			PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().y));

		//convert degrees to radians
		float rotation = DEG_TO_RAD(getGameObject()->getTransform()->getRotation());

		//set transform
		b2transform.Set(position, rotation);
	}
}

void PolygonCollider::load(json::JSON& componentData)
{
	Component::load(componentData);
	//create ICollidable Fixture Definition
	if (componentData.hasKey("vertices")) {

		vertCount = 0;
		for (int i = 0; i < componentData["vertices"].length(); i++)
		{
			vertices[i].Set(
				PIXEL_TO_METER(componentData["vertices"][i]["x"].ToFloat()),
				PIXEL_TO_METER(componentData["vertices"][i]["y"].ToFloat())
				);
			vertCount++;
		}
	}
	trigger = componentData["trigger"].ToBool();

	fixtureDefinition.shape = nullptr;
	if (componentData.hasKey("fixture"))
	{
		fixtureDefinition.density = componentData["fixture"]["density"].ToFloat();
		fixtureDefinition.friction = componentData["fixture"]["friction"].ToFloat();
		fixtureDefinition.restitution = componentData["fixture"]["restitution"].ToFloat();
	}
}
