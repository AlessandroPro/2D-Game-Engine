///-------------------------------------------------------------------------------------------------
// file: FileSystem.h
//
// author: Aditya Dinesh & Shreyas Babu
// date: 11/29/2019
//
// summary:	FileSystem::update
///-------------------------------------------------------------------------------------------------
//
// author: Shreyas Babu
// date: 11/29/2019
//
// summary: FileSystem::load, FileSystem::parseJSON, FileSystem::loadAsset, FileSystem::loadRenderSettings
//
///-------------------------------------------------------------------------------------------------
//
// author: Aditya Dinesh
// date: 11/29/2019
//
// summary: FileSystem::unload, FileSystem::getCurrentLevel 
//
///-------------------------------------------------------------------------------------------------


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
	if (removeFiles.size() > 0)																// if there is any file to unload
	{
		for (auto iter : removeFiles)
		{
			GameObjectManager::instance().unload(fileData.find(iter)->first);
			//AssetManager::instance().unloadFile(fileData.find(iter)->first);
			GameObjectManager::instance().unload(iter);
			AssetManager::instance().UnloadLevelAssets(iter);
			fileData.erase(iter);															// find the file in the cached data and removed it
		}
		removeFiles.clear();																// clear the list used to store remove fileIds
	}

	if (loadFiles.size() > 0)																// if there is any file to load
	{
		for (auto iter : loadFiles)
		{
			//AssetManager::instance().load(iter.second, iter.first);
			GameObjectManager::instance().load(iter.second, iter.first);
			//RenderSystem::instance().load(iter.second, iter.first);
			fileData.emplace(iter.first, iter.second);										// add the loaded files to the fileData map
			AssetManager::instance().LoadLevelAssets(iter.second , iter.first);
			GameObjectManager::instance().load(iter.second, iter.first);
			if (iter.first == currentLevel)
			{
				RenderSystem::instance().load(iter.second, iter.first);
			}
			fileData.emplace(iter.first, iter.second);										// find the file in the cached data and removed it
		}
		loadFiles.clear();																	// clear the list used to store loadFiles
	}
}


void FileSystem::load(std::string& fileName, bool isLevelFile)								//Method to load a file
{
	json::JSON fileJSON = parseJSON(fileName);
	bool isLoaded = false;
	if (isEmptyJSON != true)
	{
		STRCODE fileId = getHashCode(fileName.c_str());

		for (auto itr : removeFiles)
		{
			if (itr == fileId)
			{
				isLoaded = true;
			}
		}

		if (fileData.count(fileId) == 0 || isLoaded == true)
		{
			loadFiles.emplace(fileId,fileJSON);
			isLoaded = false;
		}
		else
		{
			LOG("File Already Loaded  , please Unload First")
		}

		if (isLevelFile == true)			// check if the file is a level file and not protected. Then set it as current level
		{
			if (currentLevel != NULL)
			{
				levels.push_back(currentLevel);
			}
			currentLevel = fileId;
		}

	}
	else
	{
		LOG(" JSON is empty , not in .json format or File doesn't exist");
	}
}

void FileSystem::unload(std::string& fileName)												//Method to unload a file
{
	STRCODE fileId = getHashCode(fileName.c_str());											// Convert filepath to STRCODE

	if (fileId == currentLevel)
	{
		if (levels.empty() != true)
		{
			levels.pop_back();
			currentLevel = levels.back();
		}
		else
		{
			currentLevel = 0;
		}
	}
	else if(levels.empty() != true)
	{
		for (auto i = levels.begin(); i < levels.end(); i++)
		{
			if (*i == fileId)
			{
				i = levels.erase(i);
				break;
			}
		}
	}
	removeFiles.push_back(fileId);
}

json::JSON FileSystem::loadAsset(std::string& fileName)										//pass the Json file to the Asset Manager
{
	return parseJSON(fileName);
}

json::JSON FileSystem::loadRenderSettings(std::string& fileName)
{
	return parseJSON(fileName);
}

json::JSON FileSystem::parseJSON(std::string& fileName)										//Method to parse the Json FIle 
{
	std::ifstream inputStream(fileName);
	std::string JSONstr((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());

	if (JSONstr.empty() == true || JSONstr == "" || !inputStream)							// check if JSON is empty , not in .json format or File doesn't exist
	{
		isEmptyJSON = true;
		return NULL;
	}
	else
	{
		return (json::JSON::Load(JSONstr));
	}
}

STRCODE FileSystem::getCurrentLevel()														//returns current loaded level
{
	if (currentLevel != NULL)
	{
		return currentLevel;
	}
	else
	{
		LOG("No level has been loaded");
		return 0;
	}
}