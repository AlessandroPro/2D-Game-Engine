#include "Core.h"
#include "TextureAsset.h"

IMPLEMENT_DYNAMIC_CLASS(TextureAsset)

TextureAsset::TextureAsset()
{
}

TextureAsset::~TextureAsset()
{
}

sf::Texture TextureAsset::getTexture()
{
	return texture;
}