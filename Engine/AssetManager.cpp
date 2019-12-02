#include "Core.h"
#include "AssetManager.h"
#include "FileSystem.h"

AssetManager::~AssetManager()
{
	for (auto asset : assets)
	{
		if (asset.second != nullptr)
		{
			delete asset.second;
		}
	}
	assets.clear();
	for (auto defaultAsset : defaultAssets)
	{
		if (defaultAsset.second != nullptr)
		{
			delete defaultAsset.second;
		}
	}
	defaultAssets.clear();
}

void AssetManager::initialize()
{
	//Initialize Default Assets
	std::string defaultAssetsFile = "../Assets/DefaultAssets/DefaultAssets.meta";
	json::JSON defaultAssetInfo = FileSystem::instance().loadAsset(defaultAssetsFile);
	LoadDefaultAssets(defaultAssetInfo, GUIDToSTRCODE(defaultAssetsFile));
}

void AssetManager::update(float deltaTime)
{
}

void AssetManager::LoadDefaultAssets(json::JSON& node, STRCODE fileID)
{
	//Create Default Assets
	//std::string defaultAssetFilePath = "../Assets/DefaultAssets/DefaultAssets.meta";
	//FileSystem::instance().load(defaultAssetFilePath, false);

	if (node.hasKey("resources"))
	{
		json::JSON levelResourcesNode = node["resources"];
		for (auto& defaultAssetMeta : levelResourcesNode.ArrayRange())
		{
			//Fetch AssetData for the current meta from FileManager
			std::string assetFile = defaultAssetMeta.ToString();
			json::JSON assetInformation = FileSystem::instance().loadAsset(assetFile);

			//Fetch the required asset data
			_ASSERT_EXPR(assetInformation.hasKey("class"), "asset Meta Node missing class Name");
			std::string className = assetInformation["class"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("guid"), "asset Meta Node missing GUID");
			std::string guid = assetInformation["guid"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("path"), "asset Meta Node missing file path");
			std::string assetPath = assetInformation["path"].ToString();

			//Create STRCODE from the guid for the asset
			STRCODE uid = GUIDToSTRCODE(guid);

			//Check if the asset already exists, if it does not, create new
			if (!defaultAssets.count(uid))
			{
				defaultAssets.emplace(uid, CreateAssetT(className, guid, assetPath));
			}

			//Add the loading file ID to the references
			defaultAssets[uid]->references.push_back(fileID);
		}
	}
}

void AssetManager::LoadLevelAssets(json::JSON& node, STRCODE fileID)
{
	//Check if the JSON has 'resources' to load
	if (node.hasKey("resources"))
	{
		json::JSON levelResourcesNode = node["resources"];
		for (auto& assetMeta : levelResourcesNode.ArrayRange())
		{
			//Fetch AssetData for the current meta from FileManager
			std::string assetFile = assetMeta.ToString();
			json::JSON assetInformation = FileSystem::instance().loadAsset(assetFile);

			//Fetch the required asset data
			_ASSERT_EXPR(assetInformation.hasKey("class"), "asset Meta Node missing class Name");
			std::string className = assetInformation["class"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("guid"), "asset Meta Node missing GUID");
			std::string guid = assetInformation["guid"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("path"), "asset Meta Node missing file path");
			std::string assetPath = assetInformation["path"].ToString();

			//Create STRCODE from the guid for the asset
			STRCODE uid = GUIDToSTRCODE(guid);

			//Check if the asset already exists, if it does not, create new
			if (!assets.count(uid))
			{
				assets.emplace(uid, CreateAssetT(className, guid, assetPath));
			}

			//Add the loading file ID to the references
			assets[uid]->references.push_back(fileID);
		}
	}
}

void AssetManager::UnloadLevelAssets(STRCODE fileID)
{
	std::map<STRCODE, Asset*>::iterator iteratorAsset = assets.begin();
	while (iteratorAsset != assets.end())
	{
		for (auto iteratorReference = iteratorAsset->second->references.begin(); iteratorReference != iteratorAsset->second->references.end(); iteratorReference++)
		{
			//Check if the asset has a reference of the file ID, if does, remove the reference
			if (*iteratorReference == fileID)
			{
				iteratorReference = iteratorAsset->second->references.erase(iteratorReference);
				if (iteratorReference == iteratorAsset->second->references.end())
				{
					break;
				}
			}
		}

		//If there is no reference to any file, remove the asset
		if (iteratorAsset->second->references.empty())
		{
			delete iteratorAsset->second;
			iteratorAsset = assets.erase(iteratorAsset);
		}
		else
		{
			iteratorAsset++;
		}
	}

}

Asset* AssetManager::CreateAssetT(std::string& className, std::string& guid, std::string& assetPath)
{
	Asset* asset = (Asset*)CRtti::constructObject(className.c_str());
	asset->load(guid, assetPath);
	asset->initialize();
	return asset;
}

Asset* const AssetManager::GetAssetByGUID(std::string guid)
{
	STRCODE uuid = getHashCode(guid.c_str());
	if (assets.count(uuid))
	{
		return assets[uuid];
	}
	else
	{
		return nullptr;
	}
}

Asset* AssetManager::GetAssetBySTRCODE(STRCODE uuid)
{
	if (assets.count(uuid))
	{
		return assets[uuid];
	}
	else
	{
		return nullptr;
	}
}

Asset* AssetManager::GetDefaultAssetOfType(std::string classType)
{
	for (auto defaultAsset : defaultAssets)
	{
		if (defaultAsset.second->getDerivedClassName() == classType)
		{
			return defaultAsset.second;
		}
	}
	return nullptr;
}
