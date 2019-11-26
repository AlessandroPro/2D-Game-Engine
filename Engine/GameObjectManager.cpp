#include "Core.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "AssetManager.h"

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

	deleteFromRemoveList();
}

void GameObjectManager::load(json::JSON& node)
{
	if (node.hasKey("GameObjects"))
	{
		json::JSON gameObjectsNode = node["GameObjects"];
		for (auto& gameObjectNode : gameObjectsNode.ArrayRange())
		{
			_ASSERT_EXPR(gameObjectNode.hasKey("class"), "Missing class name");

			std::string className = gameObjectNode["class"].ToString();

			GameObject* newGameObject = new GameObject();
			//newGameObject->load(gameObjectNode);
			newGameObject->initialize();
			addGameObject(newGameObject);
		}
	}
}

void GameObjectManager::unload(STRCODE levelID)
{
	//for (auto gameObject : gameObjects)
	//{
	//	if (gameObject.second != nullptr && gameObject.second->levelID == levelID)
	//	{
	//		removeGameObject(gameObject.second);
	//	}
	//}

	////deleteFromRemoveList();
}

void GameObjectManager::deleteFromRemoveList()
{
	//Created this as a function since it would be written multiple times otherwise
	for (auto gameObject : gameObjectsToRemove)
	{
		if (gameObject != nullptr)
		{
			delete gameObject;
		}
	}
	gameObjectsToRemove.clear();
}

//json::JSON GameObjectManager::save()
//{
//	for (auto gameObject : gameObjects)
//	{
//
//	}
//}

void GameObjectManager::initialize()
{
	for (auto gameObject : gameObjects)
	{
		if (gameObject.second != nullptr)
		{
			gameObject.second->initialize();
		}
	}
}

void GameObjectManager::update(float deltaTime)
{
	deleteFromRemoveList();

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

	//for (auto gameObject : gameObjects)
	//{
	//	if (gameObject.second != nullptr && gameObject.second->getComponent(compType) != nullptr)
	//	{
	//		returnList.push_back(gameObject.second);
	//	}
	//}

	return returnList;
}

GameObject* GameObjectManager::createGameObject()
{
	GameObject* newGameObj = new GameObject();

	newGameObj->initialize();
	addGameObject(newGameObj);

	return newGameObj;
}

GameObject* GameObjectManager::createGameObjectWithComponents(std::list<std::string>& comTypes)
{
	GameObject* newGameObject = new GameObject();

	newGameObject->initialize();
	//newGameObject->createComponents(comTypes);
	addGameObject(newGameObject);
	return newGameObject;
}

GameObject* GameObjectManager::instantiatePrefab(STRCODE prefabUID)
{
	//PrefabAsset* prefab = AssetManager::instance().getAssetByUUID(prefabUID);

	GameObject* newGameObject = new GameObject();
	//newGameobject->load(prefab.getPrefab());
	newGameObject->initialize();
	addGameObject(newGameObject);

	return newGameObject;
}

