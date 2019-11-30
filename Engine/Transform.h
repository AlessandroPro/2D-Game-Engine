#pragma once
#include "Component.h"

class Transform : public Component
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Transform, Component)

public:
	enum class Direction
	{
		Up,
		Down,
		Left,
		Right
	};

private:
	sf::Transformable transform;
	sf::Vector2f forward;
	std::map<Direction, bool> lockedDirections;

protected:
	void initialize() override;

public:

	Transform() ;
	~Transform() = default;
	void update(float deltaTime) override;
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

