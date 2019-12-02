///-------------------------------------------------------------------------------------------------
// file: PrefabAsset.h
//
// author: Huzaifa Saboowala
// date: 11/25/2019
//
// summary:	Prefab Asset class
///-------------------------------------------------------------------------------------------------
#ifndef _PREFABASSET_H
#define _PREFABASSET_H
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
	void initialize() override;
	void load(std::string GUID, std::string assetPath) override;

public:
	json::JSON& getPrefab();
};

#endif