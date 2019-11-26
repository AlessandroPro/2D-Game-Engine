#pragma once
#include "Object.h"

class Asset : public Object
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Asset,Object)

protected:
	Asset() = default;
	~Asset();
	void initialize(std::string GUID);

	friend class AssetManager;
};