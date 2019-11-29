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
#include "Transform.h"

class Sprite : public Component, IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Sprite, Component)
	sf::Sprite* sprite = nullptr;
	STRCODE textureAssetID = -1;
	sf::Texture texture;
	sf::IntRect dimensions;
	Transform* transform = nullptr;

public:
	Sprite();
	~Sprite();
	void update(float deltaTime) override;
    void initialize() override;
    virtual void render(sf::RenderWindow* _window) override;
	void load(json::JSON& node);
	void setImage(sf::Texture inTexture, sf::IntRect inDimensions);
	void setImage(sf::Sprite* inSprite) { sprite = inSprite; }

	friend class RenderSystem;
};

