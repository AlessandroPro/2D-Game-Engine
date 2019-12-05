///-------------------------------------------------------------------------------------------------
// file: AssetManager.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Asset Manager
///-------------------------------------------------------------------------------------------------
#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_
#pragma once

#include "ISystem.h"
#include "Asset.h"

class AssetManager final : public ISystem
{
private:
	std::map<STRCODE, Asset*> assets;
	std::map<STRCODE, Asset*> defaultAssets;

	AssetManager() = default;
	~AssetManager();
	AssetManager(const AssetManager& other) = default;
	AssetManager& operator= (const AssetManager& other) = default;

protected:

    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;

public:
	static AssetManager& instance()
	{
		static AssetManager _instance;
		return _instance;
	}

	void LoadDefaultAssets(json::JSON& node, STRCODE fileID);

	void LoadLevelAssets(json::JSON& node, STRCODE fileID);
	
	void UnloadLevelAssets(STRCODE fileID);

	Asset* CreateAssetT(std::string& className, std::string& guid, std::string& assetPath);

	Asset*const GetAssetByGUID(std::string guid);
	Asset* GetAssetBySTRCODE(STRCODE);
	Asset* GetDefaultAssetOfType(std::string classType);

	void DoNotDestroyAssetbyGUID(std::string guid);
	void DoNotDestroyAssetbySTRCODE(STRCODE);

};

#endif