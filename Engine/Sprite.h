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
	sf::Sprite* sprite = nullptr;
	std::string textureAssetGUID = "";
	STRCODE textureAssetID = -1;
	sf::IntRect dimensions;
protected:
	void load(json::JSON& node) override;
	void render(sf::RenderWindow* _window) override;
	void setImage(sf::Texture inTexture, sf::IntRect inDimensions);
public:
	Sprite() = default;
	~Sprite();
	void update(float deltaTime) override;
    void initialize() override;
	void setEnabled(bool _enabled) override;
	friend class Animation;
};

