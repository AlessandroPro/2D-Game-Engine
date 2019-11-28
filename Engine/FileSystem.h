///-------------------------------------------------------------------------------------------------
// file: FileSystem.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The File System
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
	json::JSON fileJSON;

	STRCODE fileId = 0;
	STRCODE currentLevel = 0;
	bool isEmptyJSON = false;

	json::JSON parseJSON(std::string& fileName);

protected:
    void initialize() override;
    void update(float deltaTime) override;
	
	json::JSON loadAsset(std::string& fileName);
	STRCODE getCurrentLevel();

    friend class GameEngine;
	friend class AssetManager;
	friend class GameObjectManager;


public:


	void load(std::string& fileName, bool isLevelFile);
	void unload(std::string& fileName);
	DECLARE_SINGLETON(FileSystem)
};
#endif