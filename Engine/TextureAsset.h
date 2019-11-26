#pragma once
#include "Asset.h"
class TextureAsset : public Asset
{
	DECLARE_DYNAMIC_DERIVED_CLASS(TextureAsset, Asset)

private:
	sf::Texture texture;

protected:
	TextureAsset();
	~TextureAsset();
	void initialize(std::string GUID, std::string assetPath) override;

public:
	sf::Texture	getTexture();
};