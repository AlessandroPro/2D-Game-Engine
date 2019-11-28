#include "Core.h"
#include "AssetManager.h"

void AssetManager::initialize()
{
}

void AssetManager::update(float deltaTime)
{
}

void AssetManager::loadLevelAssets(json::JSON& node, STRCODE fileID)
{
	//Check if the JSON has 'resources' to load
	if (node.hasKey("resources"))
	{
		json::JSON levelResourcesNode = node["resources"];
		for (auto& assetMeta : levelResourcesNode.ArrayRange())
		{
			//Fetch AssetData for the current meta from FileManager
			std::ifstream assetMetaInputStream(assetMeta.ToString());
			std::string assetMetaStr((std::istreambuf_iterator<char>(assetMetaInputStream)), std::istreambuf_iterator<char>());
			json::JSON assetInformation = json::JSON::Load(assetMetaStr);


			//Fetch the required asset data
			_ASSERT_EXPR(assetInformation.hasKey("class"), "asset Meta Node missing class Name");
			std::string className = assetInformation["class"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("guid"), "asset Meta Node missing GUID");
			std::string guid = assetInformation["guid"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("path"), "asset Meta Node missing file path");
			std::string assetPath = assetInformation["path"].ToString();

			//Create STRCODE from the guid for the asset
			STRCODE uid = getHashCode(guid.c_str());

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

void AssetManager::unloadLevelAssets(STRCODE fileID)
{
	std::map<STRCODE, Asset*>::iterator iteratorAsset = assets.begin();
	while (iteratorAsset != assets.end())
	{
		for (auto const& iteratorReference : iteratorAsset->second->references)
		{
			//Check if the asset has a reference of the file ID, if does, remove the reference
			if (iteratorReference == fileID)
			{
				iteratorAsset->second->references.remove(fileID);
			}
		}

		//If there is no reference to any file, remove the asset
		if (iteratorAsset->second->references.size <= 0)
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

Asset* AssetManager::getAssetByGUID(std::string guid)
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

Asset* AssetManager::getAssetBySTRCODE(STRCODE uuid)
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

