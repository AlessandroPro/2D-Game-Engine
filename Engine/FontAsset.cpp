#include "Core.h"
#include "FontAsset.h"

IMPLEMENT_DYNAMIC_CLASS(FontAsset)

FontAsset::FontAsset()
{
}

FontAsset::~FontAsset()
{
}

void FontAsset::initialize(std::string GUID, std::string assetPath)
{
}

sf::Font FontAsset::getFont()
{
	return font;
}