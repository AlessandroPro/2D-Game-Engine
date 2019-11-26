#pragma once
#include "Asset.h"
class PrefabAsset : public Asset
{
	DECLARE_DYNAMIC_DERIVED_CLASS(PrefabAsset,Asset)

private:
	json::JSON gameObjectInfo;

protected:
	PrefabAsset();
	~PrefabAsset();
	void initialize(std::string GUID, std::string assetPath) override;

public:
	json::JSON& getPrefab();
};