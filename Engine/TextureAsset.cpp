#include "Core.h"
#include "TextureAsset.h"

IMPLEMENT_DYNAMIC_CLASS(TextureAsset)

TextureAsset::TextureAsset()
{
}

TextureAsset::~TextureAsset()
{
}

void TextureAsset::initialize(std::string GUID, std::string assetPath)
{
	
}

sf::Texture TextureAsset::getTexture()
{
	return texture;
}