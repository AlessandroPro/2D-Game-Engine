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

public:
	sf::Font getFont();
};