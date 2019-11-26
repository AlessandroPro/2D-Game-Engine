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

class InputManager
{
private:
	std::list<sf::Event> events;

public:
    static InputManager& instance()
    {
        static InputManager _instance;
        return _instance;
    }

    void initialize();
    void update();

	const std::list<sf::Event>& getEvents() { return events; }

private:
    InputManager() = default;
    ~InputManager() = default;
    InputManager(InputManager const&) = delete;
};

#endif