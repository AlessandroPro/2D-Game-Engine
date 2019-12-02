///-------------------------------------------------------------------------------------------------
// file: FileSystem.h
//
<<<<<<< HEAD
// author: Aditya Dinesh & Shreyas Babu
// date: 11/24/2019
=======
// author: Aditya Dinesh
// date: 11/29/2019
//
// summary:	FileSystem Unload, Update, GetCurrentLevel
//
///-------------------------------------------------------------------------------------------------
//
// author: Shreyas Babu
// date: 11/29/2019
//
// summary: Filesystem Load file, Load Asset data, Load Render data, Update
>>>>>>> Development
//
///-------------------------------------------------------------------------------------------------
#ifndef _FILESYSTEM_H_
#define _FILESYSTEM_H_
#pragma once

#include "ISystem.h"

class FileSystem final : public ISystem
{
private:
	std::map<STRCODE, json::JSON> fileData;
	std::map<STRCODE, json::JSON> loadFiles;
	std::list<STRCODE> removeFiles;
	std::vector<STRCODE> levels;

	STRCODE fileId = 0;
	STRCODE currentLevel = 0;
	bool isEmptyJSON = false;

	json::JSON parseJSON(std::string& fileName);

protected:
    void initialize() override;
    void update(float deltaTime) override;
	
	json::JSON loadAsset(std::string& fileName);
	json::JSON loadRenderSettings(std::string& fileName);
	STRCODE getCurrentLevel();

    friend class GameEngine;
	friend class AssetManager;
	friend class RenderSystem;
	friend class GameObjectManager;


public:


	void load(std::string& fileName, bool isLevelFile);
	void unload(std::string& fileName);
	DECLARE_SINGLETON(FileSystem)
};
#endif