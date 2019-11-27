#include "Core.h"
#include "PolygonCollider.h"
#include "RigidBody.h"

PolygonCollider::PolygonCollider()
{
}

PolygonCollider::~PolygonCollider()
{
}

void PolygonCollider::initialize()
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
}

void PolygonCollider::update(float deltaTime)
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
	//		gameObject.getTransform().getPosition().x * 0.01f,
	//		gameObject.getTransform().getPosition().y * 0.01f);

	//	//convert degrees to radians
	//	float rotation = DEG_TO_RAD(gameObject.getTransform().getRotation());

	//	//set transform
	//	b2transform.Set(position, rotation);
	//}
}

void PolygonCollider::load(json::JSON& componentData)
{

}
