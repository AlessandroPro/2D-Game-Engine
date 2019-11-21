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

#include "ISystem.h"

class GameObjectManager final : public ISystem
{
protected:
    void initialize() override;
    void update(float deltaTime) override;

public:
	static GameObjectManager& instance()
	{
		static GameObjectManager _instance;
		return _instance;
	}

private:
    GameObjectManager() = default;
    ~GameObjectManager();
    GameObjectManager(const GameObjectManager& other) = default;
    GameObjectManager& operator= (const GameObjectManager& other) = default;

    friend class GameEngine;
};

#endif