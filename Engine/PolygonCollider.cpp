#include "Core.h"
#include "PolygonCollider.h"
#include "RigidBody.h"

IMPLEMENT_DYNAMIC_CLASS(PolygonCollider)

PolygonCollider::PolygonCollider()
{
}

PolygonCollider::~PolygonCollider()
{
}

void PolygonCollider::setTrigger(bool b)
{
	trigger = b;
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
	//else
	//{
	//	staticCollider =  true;
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
		//	PIXEL_TO_METER(gameObject.getTransform().getPosition().x),
		//	PIXEL_TO_METER(gameObject.getTransform().getPosition().y);

	//	//convert degrees to radians
	//	float rotation = DEG_TO_RAD(gameObject.getTransform().getRotation());

	//	//set transform
	//	b2transform.Set(position, rotation);
	//}
}

void PolygonCollider::load(json::JSON& componentData)
{
	//create ICollidable shape
	//create ICollidable Fixture Definition

	b2PolygonShape* polygon = new b2PolygonShape();

	//if (componentData.hasKey("vertices")) {
	//	//convert json list into a list of b2Vec2
	//	b2Vec2 vertices[b2_maxPolygonVertices];
	//	int count = 0;
	//	for (int i = 0; i < componentData["vertices"].length(); i++)
	//	{
	//		vertices[i].Set(
	//			PIXEL_TO_METER(componentData["vertices"][i]["x"].ToFloat()),
	//			PIXEL_TO_METER(componentData["vertices"][i]["y"].ToFloat())
	//			);
	//		count++;
	//	}
	//	polygon->Set(vertices, count);
	//}
	//else
	//{
	//	//if no vertices are given, create a default box
	//	polygon->SetAsBox(0.5f, 0.5f);
	//}

	//shape = polygon;
	//fixtureDefinition.shape = polygon;
	//fixtureDefinition.density = componentData["density"].ToFloat();
	//fixtureDefinition.friction = componentData["friction"].ToFloat();
	//fixtureDefinition.restitution = componentData["restitution"].ToFloat();
	//trigger = componentData["trigger"].ToBool();
}
