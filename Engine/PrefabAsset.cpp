#include "Core.h"
#include "PrefabAsset.h"

IMPLEMENT_DYNAMIC_CLASS(PrefabAsset)

PrefabAsset::~PrefabAsset()
{
}

json::JSON& PrefabAsset::getPrefab()
{
	return gameObjectInfo;
}
