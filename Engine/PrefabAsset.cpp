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
	initialized = true;
}

void PrefabAsset::load(std::string GUID, std::string assetPath)
{
	guid = GUID;
	id = GUIDToSTRCODE(GUID);
	std::ifstream prefabMetaInputStream(assetPath);
	std::string prefabMetaString((std::istreambuf_iterator<char>(prefabMetaInputStream)), std::istreambuf_iterator<char>());
	gameObjectInfo = json::JSON::Load(prefabMetaString);
}


const json::JSON& PrefabAsset::getPrefab()
{
	return gameObjectInfo;
}