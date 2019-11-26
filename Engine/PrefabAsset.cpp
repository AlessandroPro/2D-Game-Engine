#include "Core.h"
#include "PrefabAsset.h"

IMPLEMENT_DYNAMIC_CLASS(PrefabAsset)

PrefabAsset::PrefabAsset()
{
}

PrefabAsset::~PrefabAsset()
{
}

void PrefabAsset::initialize(std::string GUID, std::string assetPath)
{
}

json::JSON& PrefabAsset::getPrefab()
{
	return gameObjectInfo;
}