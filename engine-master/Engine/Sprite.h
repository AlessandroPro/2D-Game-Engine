#pragma once

#include "Component.h"
#include "IRenderable.h"

class Sprite : public Component, IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Sprite, Component)

private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	void initialize() override;

protected:
	void render(sf::RenderWindow* window) override;

	friend class RenderSystem;

};

