#include "Core.h"
#include "Transform.h"

IMPLEMENT_DYNAMIC_CLASS(Transform)

void Transform::initialize()
{
	Component::initialize();

}

Transform::Transform()
{
	transform.setPosition(sf::Vector2f(0, 0));
	transform.setScale(sf::Vector2f(0, 0));
	transform.setRotation(0.0f);
	forward = sf::Vector2f(1.0f, 0.0f);
	lockedDirections[Direction::Up] = false;
	lockedDirections[Direction::Down] = false;
	lockedDirections[Direction::Right] = false;
	lockedDirections[Direction::Left] = false;
}

void Transform::load(json::JSON& node)
{
	Component::load(node);
	if (node.hasKey("Position"))
	{
		json::JSON position = node["Position"];
		float x, y = 0.0f;
		if (position.hasKey("X"))
		{
			x = position["X"].ToFloat();
		}
		if (position.hasKey("Y"))
		{
			y = position["Y"].ToFloat();
		}
		setPosition(sf::Vector2f(x, y));
	}

	if (node.hasKey("Scale"))
	{
		json::JSON scale = node["Scale"];
		float x, y = 0.0f;
		if (scale.hasKey("X"))
		{
			x = scale["X"].ToFloat();
		}
		if (scale.hasKey("Y"))
		{
			y = scale["Y"].ToFloat();
		}
		setScale(sf::Vector2f(x, y));
	}

	if (node.hasKey("Rotation"))
	{
		json::JSON rotation = node["Rotation"];
		if (rotation.hasKey("Angle"))
		{
			setRotation(rotation["Angle"].ToFloat());
		}
	}
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
	transform.setPosition(newPos);
}

void Transform::setScale(const sf::Vector2f& newScale)
{
	transform.setScale(newScale);
}

void Transform::setRotation(float angle)
{
	transform.setRotation(angle);
	forward.x = cosf(DEG_TO_RAD(angle));
	forward.y = sinf(DEG_TO_RAD(angle));
}

void Transform::translate(const sf::Vector2f& offset)
{
	sf::Vector2f newOffset = offset;
	if (newOffset.x > 0)
	{
		if (lockedDirections.find(Direction::Right)->second)
		{
			newOffset.x = 0;
		}	
	}
	else if (newOffset.x < 0)
	{
		if (lockedDirections.find(Direction::Left)->second)
		{
			newOffset.x = 0;	
		}
	}
	if (newOffset.y > 0)
	{
		if (lockedDirections.find(Direction::Up)->second)
		{
			newOffset.y = 0;
		}
	}
	else if (newOffset.y < 0)
	{
		if (lockedDirections.find(Direction::Down)->second)
		{
			newOffset.y = 0;
		}
	}
	transform.move(newOffset);
}

void Transform::setDirectionLock(Direction direction, bool locked)
{
	lockedDirections[direction] = locked;
}

bool Transform::checkDirectionLocked(Direction direction)
{
	return lockedDirections.find(direction)->second;
}
