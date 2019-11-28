///-------------------------------------------------------------------------------------------------
// file: CollisionSystem.h
//
// editors: Rishi Barnwal , Dakshvir Rehill
//
// summary:	CollisionSystem ISystem is responsible for all physics simulations in the game world
///-------------------------------------------------------------------------------------------------
#pragma once
#ifndef _COLLISION_SYSTEM_H_
#define _COLLISION_SYSTEM_H_
#include "ISystem.h"
//Gravity in the 2D Physics World
#define GRAVITY  b2Vec2(0.f,9.8f)
//Physics resolution time step
//Change if frameRate is lower or higher than 60fps
#define PHYSICS_TIME_STEP 0.0167f
//Number of iterations the world takes to calculate velocity of bodies
//Lower it if game performance is affected
#define PHYSICS_VELOCITY_ITERATIONS 8
//Number of iterations the world takes to calculate position of bodies
//Lower it if game performance is affected
#define PHYSICS_POSITION_ITERATIONS 3

class RigidBody;
class ICollidable;
class CollisionSystem : public ISystem
{ 
	friend class GameEngine;
	friend class RigidBody;
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

	void checkCollision(RigidBody*, ICollidable*);
	void checkCollision(ICollidable*, ICollidable*);
protected:
	void initialize() override;
	void update(float deltaTime) override;

	//RigidBody Helper functions
protected:
	b2Body* CreateRigidBodyInWorld(b2BodyDef& bodyDefinition);
	void RemoveRigidBodyFromWorld(b2Body* rigidBody);
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