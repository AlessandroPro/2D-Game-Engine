#pragma once
#include "Object.h"

class Asset : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Asset, Object)
protected:
	Asset() = default;
	~Asset();

	std::list<STRCODE> references;

	virtual	void initialize();
	virtual void load(std::string GUID, std::string assetPath) = 0;

	friend class AssetManager;
};