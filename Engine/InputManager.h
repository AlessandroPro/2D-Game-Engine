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

private:
	std::map<sf::Keyboard::Key, PushState> keyMap;

	std::map<sf::Mouse::Button, PushState> mouseBtnMap;

	//The mouse position is a pixel-by-pixel measurement of where the cursor currently is on the screen
	sf::Vector2f mousePosition;

	//The uniform mouse position is a measurement of where the cursor is on the screen in terms of a percentage of how far it is
	//from the bottom or the left of the screen.
	sf::Vector2f uniformMousePosition;

	void updateKeyStates();
	void updateMouseButtonStates();

public:
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