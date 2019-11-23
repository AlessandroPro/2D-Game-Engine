///-------------------------------------------------------------------------------------------------
// file: InputManager.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Input Manager
///-------------------------------------------------------------------------------------------------
#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_
#pragma once

#include "ISystem.h"

class InputManager final : public ISystem
{
public:
	//Used to store the state of the input
	enum PushState
	{
		None, Down, Held, Up
	};

	//Used to store additional information on keys.
	struct KeyData
	{
		PushState state;
		bool alt;
		bool shift;
		bool control;
	};

private:
	std::map<sf::Keyboard::Key, KeyData> keyMap;

	//A map of all of the modifier keys that are used to shorthand check whether a key is being pressed along with one of these modifiers.
	std::map<sf::Keyboard::Key,bool> modifierKeyMap 
	{ 
		std::pair<sf::Keyboard::Key,bool>(sf::Keyboard::LControl, false), 
		std::pair<sf::Keyboard::Key,bool>(sf::Keyboard::RControl, false),
		std::pair<sf::Keyboard::Key,bool>(sf::Keyboard::LShift, false),
		std::pair<sf::Keyboard::Key,bool>(sf::Keyboard::RShift, false),
		std::pair<sf::Keyboard::Key,bool>(sf::Keyboard::LAlt, false),
		std::pair<sf::Keyboard::Key,bool>(sf::Keyboard::RAlt, false)
	};

	std::map<sf::Mouse::Button, PushState> mouseBtnMap;

	//The mouse position is a pixel-by-pixel measurement of where the cursor currently is on the screen
	sf::Vector2f mousePosition;

	//The uniform mouse position is a measurement of where the cursor is on the screen in terms of a percentage of how far it is
	//from the bottom or the left of the screen.
	sf::Vector2f uniformMousePosition;

	void updateKeyStates();
	void updateMouseButtonStates();
	void updateModifier(sf::Keyboard::Key modifierKey, bool isPressed);

public:
	KeyData& getKeyData(sf::Keyboard::Key inKey);
	PushState getKeyState(sf::Keyboard::Key inKey);
	PushState getMouseButtonState(sf::Mouse::Button inButton);
	sf::Vector2f& getMousePosition();
	sf::Vector2f& getUniformMousePosition();

protected:
    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(InputManager)
};

#endif