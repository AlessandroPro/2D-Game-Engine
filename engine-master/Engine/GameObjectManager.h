///-------------------------------------------------------------------------------------------------
// file: GameObjectManager.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Game Object Manager
///-------------------------------------------------------------------------------------------------
#ifndef _GAMEOBJECTMANAGER_H_
#define _GAMEOBJECTMANAGER_H_
#pragma once

class GameObject;

class GameObjectManager
{
private:
	std::list<GameObject*> gameObjects;

public:
    static GameObjectManager& instance()
    {
        static GameObjectManager _instance;
        return _instance;
    }

    void initialize(json::JSON& document);
    void addGameObject(GameObject* gameObject);
    void removeGameObject(GameObject* gameObject);
    void update();

private:
    GameObjectManager() = default;
    ~GameObjectManager();
    GameObjectManager(GameObjectManager const&) = delete;
};

#endif