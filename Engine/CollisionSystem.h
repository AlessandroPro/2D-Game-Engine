#pragma once
#ifndef _COLLISION_SYSTEM_H_
#define _COLLISION_SYSTEM_H_
#include "ISystem.h"
#define GRAVITY  b2Vec2(0.f,9.8f)
class Rigidbody;
class ICollidable;
class CollisionSystem : public ISystem
{ 
	friend class GameEngine;

private:
	//keep a list of all colliders and rigidbodies in the engine world
	std::list<ICollidable*> colliders; 
	std::list<RigidBody*> rigidbodies;

	b2World* physicsWorld = nullptr;

private:
	CollisionSystem();
	~CollisionSystem();
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
	inline void addCollidable(ICollidable* collider) { colliders.push_back(collider); }
	inline void removeCollidable(ICollidable* collider) { colliders.remove(collider); }

	inline void addRigidBody(RigidBody* rigidBody) { rigidbodies.push_back(rigidBody); }
	inline void removeRigidBody(RigidBody* rigidBody) { rigidbodies.remove(rigidBody); }
};

#endif