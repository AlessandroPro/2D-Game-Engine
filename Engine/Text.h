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
	//the three text modification settings below have been given default value examples in case the designer does not want to provide their own
	//A possible characterSize assignment is:
	//characterSize = 24;
	int characterSize;
	//A possible fillColor assignment is:
	//fillColor = sf::Color::Black;
	sf::Color fillColor;
	//All possible style assignments are shown below:
	//style = sf::Text::Bold;
	//style = sf::Text::Italic;
	//style = sf::Text::Regular;
	sf::Text::Style style;
	//The other two styles below cannot be assigned to the style variable and must instead be added to the text through booleans:
	//sf::Text::StrikeThrough;
	//sf::Text::Underlined;
	bool isTextStrikeThrough = false;
	bool isTextUnderlined = false;
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
	void setIsStrikeThrough(bool inIsTextStrikeThrough) { isTextStrikeThrough = inIsTextStrikeThrough; }
	void setIsUnderlined(bool inIsTextUnderlined) { isTextUnderlined = inIsTextUnderlined; }

	friend class RenderSystem;
};

