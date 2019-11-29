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
#include "Animation.h"
#include "Animator.h"
#include "Sprite.h"

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

		if(InputManager::instance().getKeyState(sf::Keyboard::A) == InputManager::PushState::Down)
		{
			sf::Texture texture;
			if (!texture.loadFromFile("C:/Users/browkeel/Desktop/realdev/architecture/Project/template/ProjectTemplate/test.png"))
			{
				// error...
			}
			std::vector<sf::IntRect> frames;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					frames.push_back(sf::IntRect(i*32, j * 32, 32, 32));
				}
			}

			std::string animrName = "Animator";
			std::string animnName = "Animation";
			Animator* animator = (Animator*)(spriteObject->getComponent(animrName));
			Animation* animation = (Animation*)(spriteObject->getComponent(animnName));
			Sprite* sprite = (Sprite*)(spriteObject->getComponent(sprName));

			animation->setSpeed(0.25f);
			animation->setName("Seizure");
			animation->setLoopingStatus(true);
			animator->addAnimation(animation);
			animation->setSpriteSheet(texture);
			animation->setFrames(frames);
			animation->setSprite(sprite);
			animator->setCurrentAnimation(animation->getName());
			animator->playCurrentAnimation();
		}

		spriteObject->getTransform()->setPosition(position);

        RenderSystem::instance().update(deltaTime.count());

        deltaTime = std::chrono::system_clock::now() - _time;
	}
}