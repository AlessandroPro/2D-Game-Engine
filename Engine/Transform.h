#pragma once
#include "Component.h"

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

class Transform : public Component
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Transform, Component)

private:
	sf::Transformable transform;
	sf::Vector2f forward;
	std::map<Direction, bool> lockedDirections;

protected:
	void initialize() override;

public:
	Transform() ;
	~Transform() = default;
	void update(float deltaTime);
	void load(json::JSON& node);
	const sf::Vector2f& getPosition();
	const sf::Vector2f& getScale();
	const sf::Vector2f& getForward();
	const float getRotation();

	void setPosition(const sf::Vector2f& newPos);
	void setScale(const sf::Vector2f& newScale);
	void setRotation(float angle);
	void translate(const sf::Vector2f& offset);
	void setDirectionLock(Direction direction, bool locked);
	bool checkDirectionLocked(Direction direction);
	
};

