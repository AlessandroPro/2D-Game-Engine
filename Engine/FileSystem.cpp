#include "Core.h"
#include "FileSystem.h"
#include "GameObjectManager.h"
#include "AssetManager.h"
#include "RenderSystem.h"
#include <Windows.h>

void FileSystem::initialize()
{
}

void FileSystem::update(float deltaTime)
{
}

void FileSystem::load(std::string fileName, bool protectedFile, bool isLevelFile)
{
	if (protectedFile == true && isLevelFile == true)
	{
		MessageBox(NULL, TEXT("Error"), TEXT("Level Cannot be Protected"), MB_OK | MB_ICONEXCLAMATION);  //check if the file is a level file and protected? if so throw an error 
	}
	else
	{
		std::ifstream inputStream(fileName);
		std::string JSONstr((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>()); 
		json::JSON fileJSON = json::JSON::Load(JSONstr);

		fileId = getHashCode(fileName.c_str());											

		fileData.emplace(fileId, fileJSON);												

		if (protectedFile == true && isLevelFile != true)				// check if the file is protected and not a level file
		{
			protectedFiles.push_back(fileId);
		}
		else if (isLevelFile == true && protectedFile != true)			// check if the file is a level file and not protected. Then set it as current level
		{
			currentLevel = fileId;
		}

		//RenderSystem::instance().loadFIle(fileJSON);
		//GameObjectManager::instance().loadFile(fileJSON);
		//AssetManager::instance().loadFile(fileJSON);
	}
}

void FileSystem::unload(std::string fileName)
{
}

STRCODE FileSystem::getCurrentLevel()
{
	return currentLevel;
}