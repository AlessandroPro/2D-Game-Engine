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

#include "Object.h"
#include "Component.h"

extern void registerClasses();

void GameEngine::initialize()
{
	registerClasses();

	// Load settings file
	std::ifstream gameSettingsInputStream("../Assets/GameSettings.json");
	std::string gameSettingsStr((std::istreambuf_iterator<char>(gameSettingsInputStream)), std::istreambuf_iterator<char>());
	json::JSON gameSettingsDocument = json::JSON::Load(gameSettingsStr);

	AssetManager::instance().initialize();
	FileSystem::instance().initialize();
	InputManager::instance().initialize();
	RenderSystem::instance().initialize(gameSettingsDocument);

	_ASSERT_EXPR(gameSettingsDocument.hasKey("GameEngine"), "GameSettings Node missing GameEngine");
	json::JSON gameEngineNode = gameSettingsDocument["GameEngine"];
	_ASSERT_EXPR(gameEngineNode.hasKey("DefaultFile"), "GameEngine Node missing DefaultFile");
	std::string defaultFile = gameEngineNode["DefaultFile"].ToString();

	// Load settings file
	std::ifstream defaultFileInputStream(defaultFile.c_str());
	std::string defaultFileStr((std::istreambuf_iterator<char>(defaultFileInputStream)), std::istreambuf_iterator<char>());
	json::JSON defaultFileDocument = json::JSON::Load(defaultFileStr);

	GameObjectManager::instance().initialize(defaultFileDocument);
}

void GameEngine::gameLoop()
{
	std::chrono::time_point<std::chrono::system_clock> _time;
	std::chrono::duration<float> delatTime;
	std::chrono::duration<float> totalTime(0);

    while (RenderSystem::instance().getWindow() != nullptr)
    {
		_time = std::chrono::system_clock::now();

		InputManager::instance().update();
		GameObjectManager::instance().update();
		RenderSystem::instance().update();

		delatTime = std::chrono::system_clock::now() - _time;
	}
}