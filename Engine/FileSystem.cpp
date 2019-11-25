#include "Core.h"
#include "FileSystem.h"
#include "GameObjectManager.h"
#include "AssetManager.h"
#include "RenderSystem.h"

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
		std::cout << "Level Cannot be Protected" << std::endl;
	}
	else
	{
		std::ifstream inputStream(fileName);
		std::string JSONstr((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
		json::JSON fileJSON = json::JSON::Load(JSONstr);

		fileId = getHashCode(fileName.c_str());

		fileData.emplace(fileId, fileJSON);

		if (protectedFile == true)
		{
			protectedFiles.push_back(fileId);
		}
		else if (isLevelFile == true && protectedFile != true)
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