#include "Core.h"
#include "AssetManager.h"

void AssetManager::initialize()
{
}

void AssetManager::update(float deltaTime)
{
}

void AssetManager::loadLevelAssets(json::JSON& node)
{
	if (node.hasKey("resources"))
	{
		json::JSON levelResourcesNode = node["resources"];
		for (auto& assetMeta : levelResourcesNode.ArrayRange())
		{
			std::ifstream assetMetaInputStream(assetMeta.ToString());
			std::string assetMetaStr((std::istreambuf_iterator<char>(assetMetaInputStream)), std::istreambuf_iterator<char>());
			json::JSON assetInformation = json::JSON::Load(assetMetaStr);

			_ASSERT_EXPR(assetInformation.hasKey("class"), "asset Meta Node missing class Name");
			std::string className = assetInformation["class"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("guid"), "asset Meta Node missing GUID");
			std::string guid = assetInformation["guid"].ToString();

			_ASSERT_EXPR(assetInformation.hasKey("path"), "asset Meta Node missing file path");
			std::string assetPath = assetInformation["path"].ToString();

			assets.emplace(getHashCode(guid.c_str()),CreateAssetT(className, guid, assetPath));
		}
	}
}

void AssetManager::unloadLevelAssets()
{
	std::map<STRCODE, Asset*>::iterator iteratorAssets = assets.begin();
	while (iteratorAssets != assets.end())
	{
		delete iteratorAssets->second;
		assets.erase(iteratorAssets++);
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

