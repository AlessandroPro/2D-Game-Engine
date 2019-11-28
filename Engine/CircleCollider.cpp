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

void CircleCollider::initialize()
{
	Component::initialize();

	//get gameobject of component
	//if current gameobject has a rigidbody component
	//add this to that rigidbody

	//RigidBody* rb = getComponent("RigidBody");
	//if (rb != nullptr) {
	//	rb->addCollidable(this);
	//	b2transform = rb->getB2Transform();
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
		//	PIXEL_TO_METER(gameObject.getTransform().getPosition().x),
		//	PIXEL_TO_METER(gameObject.getTransform().getPosition().y);
	//	
	//	//convert degrees to radians
	//	float rotation = DEG_TO_RAD(gameObject.getTransform().getRotation());

	//	//set transform
	//	b2transform.Set(position, rotation);
	//}
}

void CircleCollider::load(json::JSON& componentData)
{
	//create ICollidable shape
	//create ICollidable Fixture Definition
}

