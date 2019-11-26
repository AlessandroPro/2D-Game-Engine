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
	if (removeFiles.size() > 0)					// if there is any file to unload
	{
		for (auto iter : removeFiles)
		{
			fileData.erase(fileData.find(iter));	// find the file in the cached data and removed it
		}
		removeFiles.clear();					// clear the list used to store remove fileIds
	}
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

void FileSystem::unload(std::string& fileName)												//Method to unload a file
{
	STRCODE fileID = getHashCode(fileName.c_str());		// Convert filepath to STRCODE
	bool isSafe = true;									// A check to see if file is safe to unload

	for (auto iter : protectedFiles)		// Iterate through 'protectedFiles' list to check if the file is protected
	{
		if (iter == fileId)		// If file is present in the list i.e protected file then dont unload
		{
			isSafe = false;
			MessageBox(NULL, TEXT("This file is protected and cannot be deleted"), TEXT("Alert"), MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);
			break;
		}
	}

	if (isSafe)		// if file is safe to unload then add to the 'removeFile' list which will be deleted on update
	{
		removeFiles.push_back(fileID);
		//GameObjectManager::instance().unloadFile(fileJSON);
		//AssetManager::instance().unloadFile(fileJSON);
	}
}

json::JSON FileSystem::loadAsset(std::string& fileName)										//pass the Json file to the Asset Manager
{
	
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
		MessageBox(NULL, TEXT("No level has been loaded"), TEXT("Alert"), MB_ABORTRETRYIGNORE | MB_ICONEXCLAMATION);
	}
}