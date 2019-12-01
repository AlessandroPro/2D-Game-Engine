///-------------------------------------------------------------------------------------------------
// file: GameObjectManager.h 
//
// author: Jesse Berube
// documentation date: 11/30/2019
//
// summary:	The Game Object Manager
///-------------------------------------------------------------------------------------------------
#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_
#pragma once

#include "ISystem.h"

class GameObject;

class GameObjectManager final : public ISystem
{

private:
	std::map<STRCODE, GameObject*> gameObjects;
	std::list<GameObject*> gameObjectsToRemove;
	STRCODE currentLevel = -1;

protected:
	void initialize() override;
	void update(float deltaTime) override;
	void addGameObject(GameObject* gameObject);

public:
	static GameObjectManager& instance()
	{
		static GameObjectManager _instance;
		return _instance;
	}

	void removeGameObject(STRCODE gameObjectUID);
	void removeGameObject(GameObject* gameObject);
	GameObject* findGameObject(STRCODE gameObjectUID);
	std::list<GameObject*> getGameObjectsWithComponent(std::string& compType);
	GameObject* createGameObject();
	GameObject* instantiatePrefab(STRCODE prefabUID);
	GameObject* createGameObjectWithComponents(std::list<std::string>& comTypes);

private:
	GameObjectManager() = default;
	~GameObjectManager();
	GameObjectManager(const GameObjectManager& other) = default;
	GameObjectManager& operator= (const GameObjectManager& other) = default;


	void load(json::JSON& node, STRCODE levelID);
	void unload(STRCODE levelID);
	void deleteFromRemoveList();
	void initializeAllGameObjects();


	friend class GameEngine;
	friend class FileSystem;
};

#endif