#include "Core.h"
#include "TextureAsset.h"

IMPLEMENT_DYNAMIC_CLASS(TextureAsset)

TextureAsset::TextureAsset()
{
}

TextureAsset::~TextureAsset()
{
}

void TextureAsset::initialize()
{
}

void TextureAsset::load(std::string GUID, std::string assetPath)
{
	guid = GUID;
	id = GUIDToSTRCODE(GUID);
	texture.loadFromFile(assetPath);
}

sf::Texture TextureAsset::getTexture()
{
	return texture;
}