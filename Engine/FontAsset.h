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
	void initialize(std::string GUID, std::string assetPath) override;

public:
	sf::Font getFont();
};