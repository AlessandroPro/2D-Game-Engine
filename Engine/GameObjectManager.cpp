#include "Core.h"
#include "GameObjectManager.h"
#include "GameObject.h"

GameObjectManager::~GameObjectManager()
{
	for (auto gameObject : gameObjects)
	{
		if (gameObject.second != nullptr)
		{
			delete gameObject.second;
		}
	}
	gameObjects.clear();


	for (auto gameObject : gameObjectsToRemove)
	{
		if (gameObject != nullptr)
		{
			delete gameObject;
		}
	}
	gameObjectsToRemove.clear();
}

void GameObjectManager::load(json::JSON& node)
{
	//Need to know file format
}

void GameObjectManager::unload(STRCODE levelID)
{
	//loop through gameobjects and 
}

//json::JSON GameObjectManager::save()
//{
//
//	// TODO: insert return statement here
//	
//}

void GameObjectManager::initialize()
{
}

void GameObjectManager::update(float deltaTime)
{
	for (auto gameObject : gameObjectsToRemove)
	{
		if (gameObject != nullptr)
		{
			delete gameObject;
		}
	}
	gameObjectsToRemove.clear();

	for (auto gameObject : gameObjects)
	{
		gameObject.second->update(deltaTime);
	}
}

void GameObjectManager::addGameObject(GameObject* gameObject)
{
	//need strcode in gameobject to add
	//gameObjects.emplace(gameObject.uuid, gameObject);

}

void GameObjectManager::removeGameObject(STRCODE gameObjectUID)
{
	//Need to check if it is actually in the gameobject list
	GameObject* toRemove = findGameObject(gameObjectUID);

	if (toRemove != nullptr)
	{
		gameObjectsToRemove.push_back(toRemove);
		gameObjects.erase(gameObjectUID);
		//toRemove.removeChildren();
	}
}

void GameObjectManager::removeGameObject(GameObject* gameObject)
{
	//Need to check if it is actually in the gameobject list
	//GameObject* toRemove = findGameObject(gameObject.uuid);

	//if (toRemove != nullptr)
	//{
	//	gameObjectsToRemove.push_back(toRemove);
	//	gameObjects.erase(gameObject.uuid);
	//	//toRemove.removeChildren();
	//}
}

GameObject* GameObjectManager::findGameObject(STRCODE gameObjectUID)
{
	if (gameObjects.find(gameObjectUID) != gameObjects.end())
	{
		return gameObjects[gameObjectUID];
	}
	else
	{
		return nullptr;
	}
}


std::list<GameObject*> GameObjectManager::getGameObjectsWithComponent(std::string& compType)
{
	std::list<GameObject*> returnList;

	for (auto gameObject : gameObjects)
	{
		//Get Components and add to list
	}

	return returnList;
}

GameObject* GameObjectManager::createGameObject()
{
	GameObject* newGameObj = new GameObject();
	newGameObj->initialize();

	//gameObjects.emplace(newGameObj.uuid, newGameObj);

	return nullptr;
}

GameObject* GameObjectManager::instantiatePrefab(STRCODE prefabUID)
{
	return nullptr;
}

GameObject* GameObjectManager::createGameObjectWithComponents(std::list<std::string>& comTypes)
{
	return nullptr;
}