///-------------------------------------------------------------------------------------------------
// file: Sprite.h
//
// author: Justin Hole
// date: 11/28/2019
//
// summary:	Component that renders a texture onto the screen
///-------------------------------------------------------------------------------------------------
#ifndef _SPRITE_H_
#define _SPRITE_H_
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
	void setTextureAssetGUID(STRCODE guid) { textureAssetGUID_STRCODE = guid; }
	void setTextureAssetGUID(std::string guid) { textureAssetGUID_String = guid; }
};

#endif