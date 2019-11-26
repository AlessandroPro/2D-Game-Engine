#include "Core.h"
#include "FontAsset.h"

IMPLEMENT_DYNAMIC_CLASS(FontAsset)

FontAsset::FontAsset()
{
}

FontAsset::~FontAsset()
{
}

sf::Font FontAsset::getFont()
{
	return font;
}