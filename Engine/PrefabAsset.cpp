#include "Core.h"
#include "PrefabAsset.h"

IMPLEMENT_DYNAMIC_CLASS(PrefabAsset)

PrefabAsset::PrefabAsset()
{
}

PrefabAsset::~PrefabAsset()
{
}

void PrefabAsset::initialize()
{
}

void PrefabAsset::load(std::string GUID, std::string assetPath)
{
	std::ifstream prefabMetaInputStream(assetPath);
	std::string prefabMetaString((std::istreambuf_iterator<char>(prefabMetaInputStream)), std::istreambuf_iterator<char>());
	gameObjectInfo = json::JSON::Load(prefabMetaString);
}


json::JSON& PrefabAsset::getPrefab()
{
	return gameObjectInfo;
}