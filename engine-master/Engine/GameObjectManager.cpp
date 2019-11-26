#include "Core.h"
#include "GameObjectManager.h"
#include "GameObject.h"

GameObjectManager::~GameObjectManager()
{
	for (auto gameObject : gameObjects)
	{
		delete gameObject;
	}
}

void GameObjectManager::initialize(json::JSON &document)
{
	if (document.hasKey("GameObjects"))
	{
		json::JSON gameObjectsNode = document["GameObjects"];
		for (auto& gameObjectNode : gameObjectsNode.ArrayRange())
		{
			_ASSERT_EXPR(gameObjectNode.hasKey("className"), "gameObjectNode Node missing className");
			std::string className = gameObjectNode["className"].ToString();

			GameObject* gameObject = new GameObject();
			gameObject->initialize(gameObjectNode);
			addGameObject(gameObject);
		}
	}
}

void GameObjectManager::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

void GameObjectManager::removeGameObject(GameObject* gameObject)
{
	gameObjects.remove(gameObject);
}

void GameObjectManager::update()
{
	for (auto gameObject : gameObjects)
	{
		gameObject->update();
	}
}
