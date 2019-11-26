#include "Core.h"
#include "AssetManager.h"

void AssetManager::initialize()
{
}

void AssetManager::update(float deltaTime)
{
}

void loadLevelAssets(json::JSON& node)
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

			
		}
	}
}

void AssetManager::unloadLevelAssets()
{
}

Asset* AssetManager::CreateAssetT()
{
	return nullptr;
}

Asset* AssetManager::getAssetByGUID(std::string& guid)
{
	return nullptr;
}

Asset* AssetManager::getAssetBySTRCODE(STRCODE)
{
	return nullptr;
}

