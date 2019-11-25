#pragma once
#include "Asset.h"
class PrefabAsset : public Asset
{
	DECLARE_DYNAMIC_DERIVED_CLASS(PrefabAsset,Asset)

private:
	json::JSON gameObjectInfo;

protected:
	PrefabAsset() = default;
	~PrefabAsset();

public:
	json::JSON& getPrefab();

};