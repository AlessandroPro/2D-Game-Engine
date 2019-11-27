#include "Core.h"
#include "GameObjectManager.h"
#include "GameObject.h"
#include "AssetManager.h"
#include "FileSystem.h"

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

void GameObjectManager::load(json::JSON& node, STRCODE levelID)
{
	if (node.hasKey("GameObjects"))
	{
		json::JSON gameObjectsNode = node["GameObjects"];
		for (auto& gameObjectNode : gameObjectsNode.ArrayRange())
		{
			_ASSERT_EXPR(gameObjectNode.hasKey("class"), "Missing class name");

			std::string className = gameObjectNode["class"].ToString();

			GameObject* newGameObject = new GameObject();
			
			newGameObject->levelID = levelID;
			
			newGameObject->load(gameObjectNode);
			addGameObject(newGameObject);
		}

		initializeAllGameObjects();
	}
}

void GameObjectManager::unload(STRCODE levelID)
{
	for (auto gameObject : gameObjects)
	{
		if (gameObject.second != nullptr && gameObject.second->levelID == levelID)
		{
			if (gameObject.second->destroyOnUnload)
			{
				removeGameObject(gameObject.second);
			}
		}
	}

	//deleteFromRemoveList();
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

void GameObjectManager::initializeAllGameObjects()
{
	for (auto gameObject : gameObjects)
	{
		if (gameObject.second != nullptr)
		{
			gameObject.second->initialize();
		}
	}
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
	gameObjects.emplace(gameObject->id, gameObject);

}

void GameObjectManager::removeGameObject(STRCODE gameObjectUID)
{
	//Need to check if it is actually in the gameobject list
	GameObject* toRemove = findGameObject(gameObjectUID);

	if (toRemove != nullptr)
	{
		gameObjectsToRemove.push_back(toRemove);
		gameObjects.erase(gameObjectUID);
	}
}

void GameObjectManager::removeGameObject(GameObject* gameObject)
{
	//Need to check if it is actually in the gameobject list
	GameObject* toRemove = findGameObject(gameObject->id);

	if (toRemove != nullptr)
	{
		gameObjectsToRemove.push_back(toRemove);
		gameObjects.erase(gameObject->id);
	}
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
		if (gameObject.second != nullptr && gameObject.second->getComponent(compType) != nullptr)
		{
			returnList.push_back(gameObject.second);
		}
	}

	return returnList;
}

GameObject* GameObjectManager::createGameObject()
{
	GameObject* newGameObject = new GameObject();

	//newGameObject->levelID = FileManager::instance().getCurrentLevel();
	newGameObject->initialize();
	addGameObject(newGameObject);

	return newGameObject;
}

GameObject* GameObjectManager::createGameObjectWithComponents(std::list<std::string>& comTypes)
{
	GameObject* newGameObject = new GameObject();

	//newGameObj->levelID = FileManager::instance().getCurrentLevel();
	newGameObject->createComponents(comTypes);
	newGameObject->initialize();
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

