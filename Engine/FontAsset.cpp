#include "Core.h"
#include "FontAsset.h"

IMPLEMENT_DYNAMIC_CLASS(FontAsset)

FontAsset::FontAsset()
{
}

FontAsset::~FontAsset()
{
}

void FontAsset::initialize()
{
	initialized = true;
}

void FontAsset::load(std::string GUID, std::string assetPath)
{
	guid = GUID;
	id = GUIDToSTRCODE(GUID);
	font.loadFromFile(assetPath);
}

sf::Font FontAsset::getFont()
{
	return font;
}