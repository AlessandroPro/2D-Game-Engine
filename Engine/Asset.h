///-------------------------------------------------------------------------------------------------
// file: Asset.h
//
// author: Huzaifa Saboowala
// date: 11/25/2019
//
// summary:	Abstract Asset class
///-------------------------------------------------------------------------------------------------
#ifndef _ASSET_H
#define _ASSET_H
#pragma once

#include "Object.h"

class Asset : public Object
{
	DECLARE_ABSTRACT_DERIVED_CLASS(Asset, Object)
protected:
	Asset() = default;
	~Asset();

	std::list<STRCODE> references;

	virtual	void initialize() = 0;
	virtual void load(std::string GUID, std::string assetPath) = 0;

	friend class AssetManager;
};

#endif