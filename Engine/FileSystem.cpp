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

void FileSystem::load(std::string& fileName, bool protectedFile, bool isLevelFile)			//Method to load a file
{

	if (protectedFile == true && isLevelFile == true)										//check if the file is a level file and protected? if so throw an error 
	{
		MessageBox(NULL, TEXT("Level File Cannot Be Protected"), TEXT("Alert"), MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);
	}
	else
	{
		json::JSON fileJSON = parseJSON(fileName);

		fileId = getHashCode(fileName.c_str());											

		fileData.emplace(fileId, fileJSON);												

		if (protectedFile == true && isLevelFile != true)									// check if the file is protected and not a level file
		{
			protectedFiles.push_back(fileId);
		}
		else if (isLevelFile == true && protectedFile != true)								// check if the file is a level file and not protected. Then set it as current level
		{
			currentLevel = fileId;
		}

		//RenderSystem::instance().loadFIle(fileJSON);
		//GameObjectManager::instance().loadFile(fileJSON);
		//AssetManager::instance().loadFile(fileJSON);
	}
}

void FileSystem::unload(std::string& fileName)												//Method to unload a file
{
}

json::JSON FileSystem::loadAsset(std::string& fileName)										//pass the Json file to the Asset Manager
{
	return parseJSON(fileName);
}

json::JSON FileSystem::parseJSON(std::string& fileName)										//Method to parse the Json FIle 
{
	std::ifstream inputStream(fileName);
	std::string JSONstr((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	return (json::JSON::Load(JSONstr));
}

STRCODE FileSystem::getCurrentLevel()														//returns current loaded level
{
	if (currentLevel != NULL)
	{
		return currentLevel;
	}
	else
	{
		MessageBox(NULL, TEXT("There Is No Current Level"), TEXT("Alert"), MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);

	}
}