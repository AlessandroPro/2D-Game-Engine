#include "Core.h"
#include "PolygonCollider.h"

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
	//get the parent of the gameobject
	//keep looping till the gameobject.parent is null
	//if it is null, that means no parent
	//if current gameobject has a rigidbody component
	//add this to that rigidbody
	//break
}

void PolygonCollider::update(float deltaTime)
{
	//move b2transform if and only if staticCollider is true

	//use gameobjects getTransform function and use transform.getposition, and transform.getrotation
	//convert that sf::vector2f and convert it into b2Vec2, and convert rotation from degs to rads
	//use b2transform.set and pass in the converted b2vec2, and the radians
}

void PolygonCollider::load(json::JSON& file)
{
}
