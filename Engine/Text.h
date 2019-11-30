///-------------------------------------------------------------------------------------------------
// file: Text.h
//
// author: Justin Hole
// date: 11/29/2019
//
// summary:	A component that renders text onto the screen
///-------------------------------------------------------------------------------------------------

#pragma once

#include "Component.h"
#include "IRenderable.h"
#include "Transform.h"

class Text : public Component, IRenderable
{
	DECLARE_DYNAMIC_DERIVED_CLASS(Text, Component)
	sf::Text* text = nullptr;
	STRCODE fontAssetID = -1;
	sf::Font font;
	std::string string;
	//the three text modification settings below have been given default values in case the designer does not want to provide their own
	int characterSize = 24;
	sf::Color fillColor = sf::Color::Black;
	sf::Text::Style style = sf::Text::Regular;
	//All possible style assignments are shown below:
	//sf::Text::Style style = sf::Text::Bold;
	//sf::Text::Style style = sf::Text::Italic;
	//sf::Text::Style style = sf::Text::Regular;
	//sf::Text::Style style = sf::Text::StrikeThrough;
	//sf::Text::Style style = sf::Text::Underlined;
	Transform* transform = nullptr;

public:
	Text();
	~Text();
	void update(float deltaTime) override;
	void initialize() override;
	virtual void render(sf::RenderWindow* _window) override;
	void load(json::JSON& node);
	void setText(sf::Font inFont, std::string inString, int inCharacterSize, sf::Color inFillColor, sf::Text::Style inStyle);
	void setText(sf::Text* inText) { text = inText; }

	friend class RenderSystem;
};

