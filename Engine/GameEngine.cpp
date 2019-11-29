///-------------------------------------------------------------------------------------------------
// file: GameEngine.cpp
//
// author: Willia Barry
// date: 10/28/2019
//
// summary:	The Game Engine
///-------------------------------------------------------------------------------------------------
#include "Core.h"
#include "GameEngine.h"

#include "AssetManager.h"
#include "FileSystem.h"
#include "GameObjectManager.h"
#include "InputManager.h"
#include "RenderSystem.h"
#include "Camera.h"

extern void registerEngineClasses();

void GameEngine::initialize(ISystem* _projectEngine)
{
    registerEngineClasses();
    
	AssetManager::instance().initialize();
	FileSystem::instance().initialize();
	InputManager::instance().initialize();
	RenderSystem::instance().initialize();
    GameObjectManager::instance().initialize();
    projectEngine = _projectEngine;
    if (projectEngine != nullptr)
    {
        projectEngine->initialize();
    }
}

void GameEngine::gameLoop()
{
	std::chrono::time_point<std::chrono::system_clock> _time;
	std::chrono::duration<float> deltaTime(0);
	std::chrono::duration<float> totalTime(0);

    while (true)
    {
		_time = std::chrono::system_clock::now();

		InputManager::instance().update(deltaTime.count());

        FileSystem::instance().update(deltaTime.count());

        AssetManager::instance().update(deltaTime.count());

        GameObjectManager::instance().update(deltaTime.count());
		
        if (projectEngine != nullptr)
        {
            projectEngine->update(deltaTime.count());
        }


		std::string& sprName = spriteName;
		GameObject* spriteObject = GameObjectManager::instance().getGameObjectsWithComponent(sprName).front();
		sf::Vector2f position = spriteObject->getTransform()->getPosition();

		if(InputManager::instance().getKeyState(sf::Keyboard::Down) == InputManager::PushState::Held)
		{
			position.y--;
		}
		if (InputManager::instance().getKeyState(sf::Keyboard::Up) == InputManager::PushState::Held)
		{
			position.y++;
		}
		if (InputManager::instance().getKeyState(sf::Keyboard::Left) == InputManager::PushState::Held)
		{
			position.x--;
		}
		if (InputManager::instance().getKeyState(sf::Keyboard::Right) == InputManager::PushState::Held)
		{
			position.x++;
		}
		spriteObject->getTransform()->setPosition(position);

        RenderSystem::instance().update(deltaTime.count());

        deltaTime = std::chrono::system_clock::now() - _time;
	}
}