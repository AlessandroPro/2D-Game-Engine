///-------------------------------------------------------------------------------------------------
// file: Sprite.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	Component
///-------------------------------------------------------------------------------------------------
#pragma once

#include "Component.h"
#include "IRenderable.h"

class Sprite : public Component, IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Sprite, Component)

private:
	std::string textureAssetGUID_String;
	STRCODE textureAssetGUID_STRCODE;
	sf::Texture texture;
	sf::IntRect dimensions; //might not be implementing this in later versions
	sf::Sprite sprite;

protected:
	sf::Texture findTexture(STRCODE guid);
	sf::Texture findTexture(std::string guid);
	void initialize() override;
	void update(float deltaTime) override;
	virtual void render(sf::RenderWindow* _window) override;

	friend class RenderSystem;

public:
	Sprite();
	~Sprite();
	void setTextureAssetGUID(STRCODE guid);
	void setTextureAssetGUID(std::string guid);
};