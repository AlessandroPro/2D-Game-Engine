#include "Core.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(Transform)

void Transform::initialize()
{
}

Transform::Transform()
{
	type = "Transform";
}

const sf::Vector2f& Transform::getPosition()
{
	return transform.getPosition();
}

const sf::Vector2f& Transform::getScale()
{
	return transform.getScale();
}

const sf::Vector2f& Transform::getForward()
{
	return forward;
}

const float Transform::getRotation()
{
	return transform.getRotation();
}

void Transform::setPosition(const sf::Vector2f& newPos)
{
}

void Transform::setScale(const sf::Vector2f& newScale)
{
}

void Transform::setRotation(float angle)
{
}

void Transform::translate(const sf::Vector2f& offset)
{
}

void Transform::setDirectionLock(Direction direction, bool locked)
{
}

bool Transform::checkDirectionLocked(Direction direction)
{
	return false;
}
