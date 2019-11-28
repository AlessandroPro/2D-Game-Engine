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
	DECLARE_ABSTRACT_DERIVED_CLASS(Sprite, Component)

public:
	void update(float deltaTime) override;
    void initialize() override;
    virtual void render(sf::RenderWindow* _window) override;

	friend class RenderSystem;
};

