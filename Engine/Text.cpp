#include "Core.h"
#include "Text.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "AssetManager.h"

IMPLEMENT_DYNAMIC_CLASS(Text)

Text::Text()
{
}

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
	if (node.hasKey("Font"))
	{
		json::JSON fontNode = node["Font"];

		if (fontNode.hasKey("ID"))
		{
			fontAssetID = fontNode["ID"].ToInt();
			//Load asset via asset manager
			//font = AssetManager::instance().getAsset(fontAssetID);
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}

	if (node.hasKey("String"))
	{
		string = node["String"].ToString();
	}
	else
	{
		return;
	}

	if (node.hasKey("Character Size"))
	{
		characterSize = node["Character Size"].ToInt();
	}
	else
	{
		return;
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
			return;
		}
	}
	else
	{
		return;
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
				return;
			}
		}
		else
		{
			return;
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
	else
	{
		return;
	}

	setText(font, string, characterSize, fillColor, style);
}

void Text::initialize()
{
	Component::initialize();
}

void Text::update(float deltaTime)
{
	if (transform == nullptr)
	{
		transform = getGameObject()->getTransform();
	}
	text->setPosition(transform->getPosition());
}

void Text::render(sf::RenderWindow* _window)
{
	if (text != nullptr && _window != nullptr)
	{
		_window->draw(*text);
	}
}

void Text::setText(sf::Font inFont, std::string inString, int inCharacterSize, sf::Color inFillColor, sf::Text::Style inStyle)
{
	font = inFont;
	string = inString;
	characterSize = inCharacterSize;
	fillColor = inFillColor;
	style = inStyle;

	text = new sf::Text();

	text->setFont(font);
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
