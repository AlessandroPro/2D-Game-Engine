#ifndef _TEXTUREASSET_H
#define _TEXTUREASSET_H
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
	void initialize() override;
	void load(std::string GUID, std::string assetPath) override;

public:
	const sf::Texture&	getTexture();
};

#endif