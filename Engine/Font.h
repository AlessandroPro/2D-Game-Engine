///-------------------------------------------------------------------------------------------------
// file: Font.h
//
// author: Justin Hole
// date: 11/29/2019
//
// summary:	A component that renders text onto the screen
///-------------------------------------------------------------------------------------------------

#pragma once

#include "Component.h"
#include "IRenderable.h"

class Font : public Component, IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Font, Component)

public:
	void update(float deltaTime) override;
	void initialize() override;
	virtual void render(sf::RenderWindow* _window) override;
};

