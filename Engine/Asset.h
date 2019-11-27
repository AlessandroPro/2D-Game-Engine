#pragma once
#include "Object.h"

class Asset : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Asset,Object)

protected:
	Asset() = default;
	~Asset();

virtual	void initialize();
virtual void load(std::string GUID, std::string assetPath);

friend class AssetManager;
};