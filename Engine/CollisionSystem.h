#pragma once
#include "Core.h"
#include "ISystem.h"
#include "ICollidable.h"
#include "RigidBody.h"

class CollisionSystem : public ISystem
{ 
	friend class GameEngine;

private:
	//keep a list of all colliders and rigidbodies
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

	//Adders and removers for lists of Icollidables and rigidbodies
	inline void addCollidable(ICollidable* ic) { colliders.push_back(ic); }
	inline void removeCollidable(ICollidable* ic) { colliders.remove(ic); }

	inline void addRigidBody(RigidBody* rb) { rigidbodies.push_back(rb); }
	inline void removeRigidBody(RigidBody* rb) { rigidbodies.remove(rb); }
};

