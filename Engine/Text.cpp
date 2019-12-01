#include "Core.h"
#include "Text.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "AssetManager.h"
#include "FontAsset.h"

IMPLEMENT_DYNAMIC_CLASS(Text)


Text::~Text()
{
	if (text != nullptr)
	{
		delete text;
	}
}

void Text::load(json::JSON& node)
{
	Component::load(node);
	if (node.hasKey("FontGUID"))
	{
		fontAssetGUID = node["FontGUID"].ToString();
		fontAssetID = GUIDToSTRCODE(fontAssetGUID);
	}

	if (node.hasKey("String"))
	{
		string = node["String"].ToString();
	}

	if (node.hasKey("Character Size"))
	{
		characterSize = node["Character Size"].ToInt();
	}

	if (node.hasKey("Fill Color"))
	{
		if (node["Fill Color"].ToString() == "Black")
		{
			fillColor = sf::Color::Black;
		}
		else if (node["Fill Color"].ToString() == "Blue")
		{
			fillColor = sf::Color::Blue;
		}
		else if (node["Fill Color"].ToString() == "Cyan")
		{
			fillColor = sf::Color::Cyan;
		}
		else if (node["Fill Color"].ToString() == "Green")
		{
			fillColor = sf::Color::Green;
		}
		else if (node["Fill Color"].ToString() == "Magenta")
		{
			fillColor = sf::Color::Magenta;
		}
		else if (node["Fill Color"].ToString() == "Red")
		{
			fillColor = sf::Color::Red;
		}
		else if (node["Fill Color"].ToString() == "White")
		{
			fillColor = sf::Color::White;
		}
		else if (node["Fill Color"].ToString() == "Yellow")
		{
			fillColor = sf::Color::Yellow;
		}
		else
		{
			fillColor = sf::Color::White;
		}
	}

	if (node.hasKey("Style"))
	{
		json::JSON styleNode = node["Style"];

		if (styleNode.hasKey("Font Style"))
		{
			if (styleNode["Font Style"].ToString() == "Bold")
			{
				style = sf::Text::Bold;
			}
			else if (styleNode["Font Style"].ToString() == "Italic")
			{
				style = sf::Text::Italic;
			}
			else if (styleNode["Font Style"].ToString() == "Regular")
			{
				style = sf::Text::Regular;
			}
			else
			{
				style = sf::Text::Regular;
			}
		}
		if (styleNode.hasKey("Strike Through"))
		{
			if (styleNode["Strike Through"].ToBool() == true)
			{
				isTextStrikeThrough = true;
			}
			else
			{
				isTextStrikeThrough = false;
			}
		}
		if (styleNode.hasKey("Underlined"))
		{
			if (styleNode["Underlined"].ToBool() == true)
			{
				isTextUnderlined = true;
			}
			else
			{
				isTextUnderlined = false;
			}
		}
	}
}

void Text::initialize()
{
	Component::initialize();
	FontAsset* asset = dynamic_cast<FontAsset*>(AssetManager::instance().GetAssetBySTRCODE(fontAssetID));
	if (asset == nullptr)
	{
		asset = static_cast<FontAsset*>(AssetManager::instance().GetDefaultAssetOfType("FontAsset"));
	}
	setText(asset->getFont(), string, characterSize, fillColor, style);
}

void Text::update(float deltaTime)
{
	text->setPosition(getGameObject()->getTransform()->getPosition());
	if (text->getString() != string)
	{
		text->setString(string);
	}
}

void Text::render(sf::RenderWindow* _window)
{
	if (text != nullptr && _window != nullptr && isEnabled())
	{
		_window->draw(*text);
	}
}

void Text::setText(sf::Font inFont, std::string inString, int inCharacterSize, sf::Color inFillColor, sf::Text::Style inStyle)
{
	string = inString;
	characterSize = inCharacterSize;
	fillColor = inFillColor;
	style = inStyle;

	text = new sf::Text();

	text->setFont(inFont);
	text->setString(string);
	text->setCharacterSize(characterSize);
	text->setFillColor(fillColor);
	if (isTextStrikeThrough && isTextUnderlined)
	{
		text->setStyle(style | sf::Text::StrikeThrough | sf::Text::Underlined);
	}
	else if (isTextStrikeThrough)
	{
		text->setStyle(style | sf::Text::StrikeThrough);
	}
	else if (isTextUnderlined)
	{
		text->setStyle(style | sf::Text::Underlined);
	}
	else
	{
		text->setStyle(style);
	}
}
