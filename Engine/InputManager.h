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
	enum InputState
	{
		None, Down, Held, Up
	};

private:
	std::map<sf::Keyboard::Key, InputState> keyMap;
	std::map<sf::Mouse::Button, InputState> mouseBtnMap;
	sf::Vector2<float> mousePosition;

public:
	InputState getKeyState(sf::Keyboard::Key inKey);
	InputState getMouseButtonState(sf::Mouse::Button inButton);
	sf::Vector2<float> getMousePosition();

protected:
    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(InputManager)


};

#endif