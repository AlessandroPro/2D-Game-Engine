#ifndef _FONTASSET_H
#define _FONTASSET_H
#pragma once
#include "Asset.h"
class FontAsset : public Asset
{
	DECLARE_DYNAMIC_DERIVED_CLASS(FontAsset, Asset)

private:
	sf::Font font;

protected:
	FontAsset();
	~FontAsset();
	void initialize() override;
	void load(std::string GUID, std::string assetPath) override;

public:
	const sf::Font& getFont();
};

#endif