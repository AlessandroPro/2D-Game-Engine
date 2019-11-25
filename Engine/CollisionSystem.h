#pragma once
#include "Core.h"
#include "ISystem.h"
#include "ICollidable.h"
#include "RigidBody.h"

class CollisionSystem : public ISystem
{ 
	friend class GameEngine;

private:
	std::list<ICollidable*> colliders;
	std::list<RigidBody*> rigidbodies;

private:
	CollisionSystem() = default;
	~CollisionSystem() = default;
	CollisionSystem(const CollisionSystem& other) = default;
	CollisionSystem& operator= (const CollisionSystem& other) = default;

protected:
	void initialize() override;
	void update(float deltaTime) override;

public:
	static CollisionSystem& instance()
	{
		static CollisionSystem _instance;
		return _instance;
	}


};

