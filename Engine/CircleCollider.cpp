#include "Core.h"
#include "CircleCollider.h"
#include "RigidBody.h"

IMPLEMENT_DYNAMIC_CLASS(CircleCollider)


CircleCollider::CircleCollider()
{
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::setTrigger(bool isTrigger)
{
	trigger = isTrigger;
	if (!staticCollider)
	{
		if (trigger)
		{
			//	RigidBody* rigidBody = getGameObject()->getComponent("RigidBody");
			//	if (rigidBody != nullptr) 
			//	{
			//		rigidBody->removeCollidable(this);
			//		b2transform = b2Transform(b2Vec2(
	//					PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().x),
	//					PIXEL_TO_METER(getGameObject()->getTransform()->getPosition().y)), 
	//					DEG_TO_RAD(getGameObject()->getTransform()->getRotation()));
			//	}
		}
	}
	else
	{

	}
}

void CircleCollider::initialize()
{
	Component::initialize();

	//get gameobject of component
	//if current gameobject has a rigidbody component
	//add this to that rigidbody
	//if (!trigger)
	//{
	//	RigidBody* rigidBody = getGameObject()->getComponent("RigidBody");
	//	if (rigidBody != nullptr) 
	//	{
	//		rigidBody->addCollidable(this);
	//		b2transform = rigidBody->getB2Transform();
	//	}
	//	else
	//	{
	//		staticCollider = true;
	//	}
	//}
	//else
	//{
	//	staticCollider =  true;
	//}
	
}

void CircleCollider::update(float deltaTime)
{
	//move b2transform if and only if staticCollider is true

	//use gameobjects getTransform function and use transform.getposition, and transform.getrotation
	//convert that sf::vector2f and convert it into b2Vec2, and convert rotation from degs to rads
	//use b2transform.set and pass in the converted b2vec2, and the radians

	//if (staticCollider) 
	//{
	//	//get transform and rotation from gameobject

	//	//convert transform to b2Transform
	//	b2Vec2 position = b2Vec2(
		//	PIXEL_TO_METER(getGameObject()->getTransform()->getPosition()->x),
		//	PIXEL_TO_METER(getGameObject()->getTransform()->getPosition()->y));
	//	
	//	//convert degrees to radians
	//	float rotation = DEG_TO_RAD(getGameObject()->getTransform()->getRotation());

	//	//set transform
	//	b2transform.Set(position, rotation);
	//}
}

void CircleCollider::load(json::JSON& componentData)
{
	//create ICollidable shape
	//create ICollidable Fixture Definition

	//b2CircleShape* circle = new b2CircleShape();
	//circle->m_p.Set(
	//	PIXEL_TO_METER(getGameObject()->getTransform()->getPosition()->x),
	//	PIXEL_TO_METER(getGameObject()->getTransform()->getPosition()->y));

	//if (componentData.hasKey("radius")) 
	//{
	//	circle->m_radius = componentData["radius"].ToFloat();
	//}
	//else
	//{
	//	circle->m_radius = 0.5f;
	//}

	//shape = circle;
	//fixtureDefinition.shape = circle;
	//fixtureDefinition.density = componentData["density"].ToFloat();
	//fixtureDefinition.friction = componentData["friction"].ToFloat();
	//fixtureDefinition.restitution = componentData["restitution"].ToFloat();
	//trigger = componentData["trigger"].ToBool();
	
}

